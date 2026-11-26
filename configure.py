#!/usr/bin/env python3

###
# Generates build files for the project.
# This file also includes the project configuration,
# such as compiler flags and the object matching status.
#
# Usage:
#   python3 configure.py
#   ninja
#
# Append --help to see available options.
###

import argparse
import sys
from pathlib import Path
from typing import Any, Dict, List

from tools.project import (
    Object,
    ProgressCategory,
    ProjectConfig,
    calculate_progress,
    generate_build,
    is_windows,
)

# Game versions
DEFAULT_VERSION = 0
VERSIONS = [
    "GFEE01",  # 0
]

parser = argparse.ArgumentParser()
parser.add_argument(
    "mode",
    choices=["configure", "progress"],
    default="configure",
    help="script mode (default: configure)",
    nargs="?",
)
parser.add_argument(
    "-v",
    "--version",
    choices=VERSIONS,
    type=str.upper,
    default=VERSIONS[DEFAULT_VERSION],
    help="version to build",
)
parser.add_argument(
    "--build-dir",
    metavar="DIR",
    type=Path,
    default=Path("build"),
    help="base build directory (default: build)",
)
parser.add_argument(
    "--binutils",
    metavar="BINARY",
    type=Path,
    help="path to binutils (optional)",
)
parser.add_argument(
    "--compilers",
    metavar="DIR",
    type=Path,
    help="path to compilers (optional)",
)
parser.add_argument(
    "--map",
    action="store_true",
    help="generate map file(s)",
)
parser.add_argument(
    "--debug",
    action="store_true",
    help="build with debug info (non-matching)",
)
if not is_windows():
    parser.add_argument(
        "--wrapper",
        metavar="BINARY",
        type=Path,
        help="path to wibo or wine (optional)",
    )
parser.add_argument(
    "--dtk",
    metavar="BINARY | DIR",
    type=Path,
    help="path to decomp-toolkit binary or source (optional)",
)
parser.add_argument(
    "--objdiff",
    metavar="BINARY | DIR",
    type=Path,
    help="path to objdiff-cli binary or source (optional)",
)
parser.add_argument(
    "--sjiswrap",
    metavar="EXE",
    type=Path,
    help="path to sjiswrap.exe (optional)",
)
parser.add_argument(
    "--ninja",
    metavar="BINARY",
    type=Path,
    help="path to ninja binary (optional)",
)
parser.add_argument(
    "--verbose",
    action="store_true",
    help="print verbose output",
)
parser.add_argument(
    "--non-matching",
    dest="non_matching",
    action="store_true",
    help="builds equivalent (but non-matching) or modded objects",
)
parser.add_argument(
    "--warn",
    dest="warn",
    type=str,
    choices=["all", "off", "error"],
    help="how to handle warnings",
)
parser.add_argument(
    "--no-progress",
    dest="progress",
    action="store_false",
    help="disable progress calculation",
)
args = parser.parse_args()

config = ProjectConfig()
config.version = str(args.version)
version_num = VERSIONS.index(config.version)

# Apply arguments
config.build_dir = args.build_dir
config.dtk_path = args.dtk
config.objdiff_path = args.objdiff
config.binutils_path = args.binutils
config.compilers_path = args.compilers
config.generate_map = args.map
config.non_matching = args.non_matching
config.sjiswrap_path = args.sjiswrap
config.ninja_path = args.ninja
config.progress = args.progress
if not is_windows():
    config.wrapper = args.wrapper
# Don't build asm unless we're --non-matching
if not config.non_matching:
    config.asm_dir = None

# Tool versions
config.binutils_tag = "2.42-2"
config.compilers_tag = "20251118"
config.dtk_tag = "v1.8.3"
config.objdiff_tag = "v3.6.1"
config.sjiswrap_tag = "v1.2.2"
config.wibo_tag = "1.0.3"

# Project
config.config_path = Path("config") / config.version / "config.yml"
config.check_sha_path = Path("config") / config.version / "build.sha1"
config.asflags = [
    "-mgekko",
    "--strip-local-absolute",
    "-I include",
    f"-I build/{config.version}/include",
    f"--defsym BUILD_VERSION={version_num}",
]
config.ldflags = [
    "-fp hardware",
    "-nodefaults",
]
if args.debug:
    config.ldflags.append("-g")  # Or -gdwarf-2 for Wii linkers
if args.map:
    config.ldflags.append("-mapunused")
    # config.ldflags.append("-listclosure") # For Wii linkers

# Use for any additional files that should cause a re-configure when modified
config.reconfig_deps = []

# Optional numeric ID for decomp.me preset
# Can be overridden in libraries or objects
config.scratch_preset_id = None

# Base flags, common to most GC/Wii games.
# Generally leave untouched, with overrides added below.
cflags_base = [
    "-nodefaults",
    "-proc gekko",
    "-align powerpc",
    "-enum int",
    "-fp hardware",
    "-Cpp_exceptions off",
    "-O4,p",
    "-inline auto",
    '-pragma "cats off"',
    '-pragma "warn_notinlined off"',
    "-maxerrors 1",
    "-nosyspath",
    "-RTTI off",
    "-fp_contract on",
    "-str reuse",
    "-multibyte",  # For Wii compilers, replace with `-enc SJIS`
    "-i include",
    f"-i build/{config.version}/include",
    f"-DBUILD_VERSION={version_num}",
    f"-DVERSION_{config.version}",
]

# Debug flags
if args.debug:
    # Or -sym dwarf-2 for Wii compilers
    cflags_base.extend(["-sym on", "-DDEBUG=1"])
else:
    cflags_base.append("-DNDEBUG=1")

# Warning flags
if args.warn == "all":
    cflags_base.append("-W all")
elif args.warn == "off":
    cflags_base.append("-W off")
elif args.warn == "error":
    cflags_base.append("-W error")

# Metrowerks library flags
cflags_runtime = [
    *cflags_base,
    "-use_lmw_stmw on",
    "-str reuse,pool,readonly",
    "-gccinc",
    "-common off",
    "-inline auto",
]

# REL flags
cflags_rel = [
    *cflags_base,
    "-sdata 0",
    "-sdata2 0",
]

config.linker_version = "GC/1.3.2"
config.shift_jis = False


# Helper function for Dolphin libraries
def DolphinLib(lib_name: str, objects: List[Object]) -> Dict[str, Any]:
    return {
        "lib": lib_name,
        "mw_version": "GC/1.2.5n",
        "cflags": cflags_base,
        "progress_category": "sdk",
        "objects": objects,
    }


# Helper function for REL script objects
def Rel(lib_name: str, objects: List[Object]) -> Dict[str, Any]:
    return {
        "lib": lib_name,
        "mw_version": "GC/1.3.2",
        "cflags": cflags_rel,
        "progress_category": "game",
        "objects": objects,
    }


Matching = True                   # Object matches and should be linked
NonMatching = False               # Object does not match and should not be linked
Equivalent = config.non_matching  # Object should be linked when configured with --non-matching


# Object is only matching for specific versions
def MatchingFor(*versions):
    return config.version in versions


config.warn_missing_config = True
config.warn_missing_source = False
config.libs = [
    {
        "lib": "game",
        "mw_version": config.linker_version,
        "cflags": cflags_base,
        "progress_category": "game",
        "objects": [
            Object(NonMatching, "auto/text_800056A0.c"),
            Object(Matching, "auto/text_80006264.c"),
            Object(Matching, "auto/text_80006314.c"),
            Object(NonMatching, "auto/text_80006388.c"),
            Object(NonMatching, "auto/text_800065B0.c"),
            Object(Matching, "auto/text_80006754.c"),
            Object(NonMatching, "auto/text_80006798.c"),
            Object(Matching, "auto/text_80006AC0.c"),
            Object(NonMatching, "auto/text_80006AF4.c"),
            Object(Matching, "auto/text_8000A950.c"),
            Object(NonMatching, "auto/text_8000AA60.c"),
            Object(NonMatching, "auto/text_8000B0XX.c"),
            Object(NonMatching, "auto/text_8000D354.c"),
            Object(NonMatching, "auto/text_8000D598.c"),
            Object(NonMatching, "auto/text_80010770.c"),
            Object(NonMatching, "auto/text_80010FF0.c"),
            Object(NonMatching, "auto/text_800119C0.c"),
            Object(NonMatching, "auto/text_80016F40.c"),
            Object(NonMatching, "auto/text_800195BC.c"),
            Object(NonMatching, "auto/text_8001EEEC.c"),
            Object(NonMatching, "auto/map_height.c"),
            Object(NonMatching, "auto/text_8001F85C.c"),
            Object(NonMatching, "auto/map_sample_height.c"),
            Object(NonMatching, "auto/text_800233D0.c"),
            Object(NonMatching, "auto/text_8002887C.c"),
            Object(NonMatching, "auto/text_800330F8.c"),
            Object(NonMatching, "auto/text_8003670C.c"),
            Object(NonMatching, "auto/text_80036834.c"),
            Object(NonMatching, "auto/text_80036DE0.c"),
            Object(Matching, "auto/unit_distance.c", mw_version="GC/3.0a3"),
            Object(NonMatching, "auto/text_8003833C.c", mw_version="GC/1.3"),
            Object(Matching, "auto/unit_stats.c"),
            Object(NonMatching, "auto/text_8003B69C.c", mw_version="GC/1.3"),
            Object(Matching, "auto/text_8003F87C.c"),
            Object(Matching, "auto/text_8003FCCC.c"),
            Object(NonMatching, "auto/text_8003FCF0.c"),
            Object(NonMatching, "auto/text_80041514.c", mw_version="GC/1.3"),
            Object(NonMatching, "auto/text_80042558.c"),
            Object(Matching, "auto/text_800536CC.c"),
            Object(NonMatching, "auto/text_800537E8.c"),
            Object(NonMatching, "auto/text_80054314.c"),
            Object(Matching, "auto/text_80054850.c"),
            Object(Matching, "auto/text_800548E8.c"),
            Object(NonMatching, "auto/text_80054C14.c"),
            Object(Matching, "auto/text_80055B64.c"),
            Object(Matching, "auto/text_80055C74.c"),
            Object(NonMatching, "auto/text_80055CE4.c"),
            Object(NonMatching, "auto/text_80059500.c"),
            Object(NonMatching, "auto/text_8005956C.c"),
            Object(NonMatching, "auto/text_8005A2A8.c"),
            Object(NonMatching, "auto/text_8005AE20.c"),
            Object(NonMatching, "auto/text_8005B760.c"),
            Object(NonMatching, "auto/text_8005B7A4.c", mw_version="GC/2.0"),
            Object(NonMatching, "auto/text_8005E644.c", mw_version="GC/2.0"),
            Object(Matching, "auto/text_8005EA14.c", mw_version="GC/2.0"),
            Object(NonMatching, "auto/text_8005EB5C.c", mw_version="GC/2.0"),
            Object(Matching, "auto/text_8005F7F0.c", mw_version="GC/1.2.5n"),
            Object(NonMatching, "auto/text_8005F84C.c"),
            Object(NonMatching, "auto/Ui_MenuWork.c"),
            Object(NonMatching, "auto/UiWin_Prims.c"),
            Object(NonMatching, "auto/MsgWin_Open.c"),
            Object(Matching, "auto/text_800725C8.c"),
            Object(NonMatching, "auto/text_80073394.c"),
            Object(NonMatching, "auto/text_80074370.c"),
            Object(NonMatching, "auto/text_8007C5E4.c"),
            Object(NonMatching, "auto/text_8007F410.c"),
            Object(Matching, "auto/text_8007F7F8.c", mw_version="GC/1.3"),
            Object(NonMatching, "auto/text_8007F844.c"),
            Object(Matching, "auto/text_80081CB0.c", mw_version="GC/1.3"),
            Object(NonMatching, "auto/text_80081CF4.c"),
            Object(NonMatching, "auto/text_80083DC0.c", mw_version="GC/1.3"),
            Object(NonMatching, "auto/text_800852BC.c", mw_version="GC/1.3"),
            Object(NonMatching, "text_80089490.c", mw_version="GC/1.3"),
            Object(NonMatching, "text_800894F8.c", mw_version="GC/1.3"),
            Object(NonMatching, "auto/text_80089980.c", mw_version="GC/1.3"),
            Object(NonMatching, "auto/text_80089A28.c", mw_version="GC/1.3"),
            Object(Matching, "auto/text_8008CD9C.c", mw_version="GC/1.3"),
            Object(Matching, "auto/text_8008CDE0.c", mw_version="GC/1.3"),
            Object(Matching, "auto/text_8008D000.c", mw_version="GC/1.3"),
            Object(NonMatching, "auto/text_8008D264.c", mw_version="GC/1.3"),
            Object(Matching, "auto/text_8008D834.c", mw_version="GC/1.3"),
            Object(NonMatching, "auto/text_8008D86C.c", mw_version="GC/1.3"),
            Object(NonMatching, "auto/text_8008DA60.c", mw_version="GC/1.3"),
            Object(NonMatching, "auto/text_8008F49C.c", mw_version="GC/1.3"),
            Object(Matching, "auto/text_8008FE24.c", mw_version="GC/1.3"),
            Object(NonMatching, "auto/text_8008FE5C.c", mw_version="GC/1.3"),
            Object(NonMatching, "auto/text_80090480.c", mw_version="GC/1.3"),
            Object(Matching, "auto/text_80091858.c", mw_version="GC/1.3"),
            Object(NonMatching, "auto/text_8009197C.c", mw_version="GC/1.3"),
            Object(Matching, "auto/text_80092414.c", mw_version="GC/1.3"),
            Object(NonMatching, "auto/text_80092438.c", mw_version="GC/1.3"),
            Object(Matching, "auto/text_800955BC.c", mw_version="GC/1.2.5n"),
            Object(NonMatching, "auto/text_80095614.c", mw_version="GC/1.3"),
            Object(Matching, "auto/text_80095850.c", mw_version="GC/1.3"),
            Object(Matching, "auto/text_800958C4.c", mw_version="GC/1.3"),
            Object(NonMatching, "auto/text_80095BB0.c", mw_version="GC/2.0"),
            Object(NonMatching, "auto/text_80097740.c", mw_version="GC/2.0"),
            Object(NonMatching, "auto/text_80097970.c", mw_version="GC/2.0"),
            Object(Matching, "auto/text_80098170.c", mw_version="GC/1.3"),
            Object(NonMatching, "auto/text_800981D0.c", mw_version="GC/1.3"),
            Object(Matching, "auto/text_80098AE4.c", mw_version="GC/1.3"),
            Object(Matching, "auto/text_80098B74.c", mw_version="GC/1.2.5n"),
            Object(Matching, "auto/text_80098B80.c", mw_version="GC/1.3"),
            Object(Matching, "auto/text_80098BAC.c", mw_version="GC/1.3"),
            Object(Matching, "auto/text_80098D04.c", mw_version="GC/1.3"),
            Object(NonMatching, "auto/text_80098D30.c", mw_version="GC/1.3"),
            Object(Matching, "auto/text_8009A5F4.c", mw_version="GC/1.3"),
            Object(NonMatching, "auto/text_8009A67C.c", mw_version="GC/1.3"),
            Object(NonMatching, "auto/text_8009A76C.c", mw_version="GC/1.3"),
            Object(NonMatching, "auto/text_8009B55C.c", mw_version="GC/1.3"),
            Object(NonMatching, "auto/text_8009EA14.c", mw_version="GC/1.3"),
            Object(NonMatching, "auto/text_8009ECF4.c", mw_version="GC/1.3"),
            Object(NonMatching, "auto/text_8009F85C.c"),
            Object(Matching, "auto/text_800A011C.c"),
            Object(Matching, "auto/text_800A0144.c"),
            Object(Matching, "auto/text_800A0170.c"),
            Object(Matching, "auto/text_800A0198.c"),
            Object(NonMatching, "auto/text_800A022C.c"),
            Object(Matching, "auto/text_800A02F4.c"),
            Object(Matching, "auto/text_800A031C.c"),
            Object(NonMatching, "auto/text_800A0348.c"),
            Object(Matching, "auto/text_800A39AC.c"),
            Object(NonMatching, "auto/text_800A39F8.c"),
            Object(NonMatching, "auto/text_800A9488.c", mw_version="GC/1.3.2r"),
            Object(Matching, "auto/text_800AD24C.c", mw_version="GC/2.0"),
            Object(NonMatching, "auto/text_800AD700.c", mw_version="GC/2.0"),
            Object(NonMatching, "auto/text_800AD724.c", mw_version="GC/2.0"),
            Object(NonMatching, "auto/text_800AE444.c", mw_version="GC/2.0"),
            Object(Matching, "auto/text_800AE52C.c", mw_version="GC/2.0"),
            Object(NonMatching, "auto/text_800AE5A8.c"),
            Object(NonMatching, "auto/icon.c", mw_version="GC/1.3"),
            Object(NonMatching, "auto/icon_copy.c", mw_version="GC/1.3"),
            Object(NonMatching, "auto/icon_rest.c", mw_version="GC/1.3"),
            Object(NonMatching, "auto/text_800C40F4.c", mw_version="GC/2.0"),
            Object(NonMatching, "auto/text_80103748.c"),
            Object(NonMatching, "auto/text_80105124.c"),
            Object(NonMatching, "auto/text_80105284.c"),
            Object(NonMatching, "auto/text_8010554C.c"),
            Object(NonMatching, "auto/text_801101D0.c"),
            Object(Matching, "auto/archive_load_proc.c"),
            Object(NonMatching, "auto/text_8011AB98.c"),
            Object(NonMatching, "auto/text_80120CCC.c"),
            Object(NonMatching, "auto/text_80127E94.c"),
            Object(NonMatching, "auto/text_8012C3D0.c"),
            Object(NonMatching, "auto/text_80132800.c", mw_version="GC/2.0"),
            Object(NonMatching, "auto/text_8013CD90.c", mw_version="GC/2.0"),
            Object(NonMatching, "auto/text_8013CDCC.c"),
            Object(NonMatching, "auto/text_801436AC.c", mw_version="GC/2.5"),
            Object(NonMatching, "auto/text_80143784.c", mw_version="GC/2.0"),
            Object(Matching, "auto/text_80149FB8.c"),
            Object(NonMatching, "auto/text_8014A370.c"),
            Object(NonMatching, "text_8014A928.c"),
            Object(NonMatching, "text_8014AC68.c"),
            Object(NonMatching, "text_8014ACE8.c"),
            Object(NonMatching, "text_8014BC10.c"),
            Object(NonMatching, "text_8014C39C.c"),
            Object(Matching, "auto/text_8014CC5C.c"),
            Object(NonMatching, "auto/text_8014CF10.c"),
            Object(NonMatching, "auto/text_8014E3A0.c"),
            Object(NonMatching, "auto/text_80163200.c", mw_version="GC/2.0"),
            Object(NonMatching, "auto/text_80181C40.c"),
            Object(NonMatching, "auto/text_80181CA4.c"),
            Object(NonMatching, "auto/text_801833E8.c"),
            Object(NonMatching, "auto/text_801A2AC4.c"),
            Object(NonMatching, "auto/text_801A7D78.c"),
            Object(NonMatching, "auto/text_801AE3F8.c"),
            Object(NonMatching, "auto/text_801B3258.c"),
            Object(Matching, "auto/text_801CCEA8.c", mw_version="GC/2.0"),
            Object(NonMatching, "auto/text_801CCED4.c"),
            Object(Matching, "auto/text_801E11AC.c"),
            Object(NonMatching, "auto/text_801E1440.c"),
            Object(NonMatching, "auto/text_801E4540.c"),
            Object(NonMatching, "auto/text_801EAA2C.c"),
            Object(NonMatching, "auto/text_801F196C.c"),
            Object(NonMatching, "auto/text_801FC634.c"),
            Object(NonMatching, "auto/text_80202300.c", mw_version="GC/1.2.5n"),
            Object(NonMatching, "auto/text_80202540.c", mw_version="GC/1.2.5n"),
            Object(NonMatching, "dolphin/mtx/quat.c", mw_version="GC/1.2.5n"),
            Object(NonMatching, "auto/text_80203778.c", mw_version="GC/1.2.5n"),
            Object(Matching, "dolphin/os/OSReboot.c", mw_version="GC/1.2.5n"),
            Object(NonMatching, "dolphin/os/OSReset.c", mw_version="GC/1.2.5n"),
            Object(NonMatching, "dolphin/os/OSResetSW.c"),
            Object(NonMatching, "dolphin/os/OSResetSW_state.c"),
            Object(NonMatching, "dolphin/os/OSSram.c", mw_version="GC/1.2.5n"),
            Object(Matching, "dolphin/os/OSSram_unlock.c", mw_version="GC/1.2.5n"),
            Object(Matching, "dolphin/os/OSSram_tail.c", mw_version="GC/1.2.5n"),
            Object(Matching, "dolphin/os/OSSram_lockbits2.c", mw_version="GC/1.2.5n"),
            Object(Matching, "dolphin/os/OSSram_lockbits3.c", mw_version="GC/1.2.5n"),
            Object(Matching, "dolphin/os/OSSram_lockbits.c", mw_version="GC/1.2.5n"),
            Object(NonMatching, "dolphin/os/OSSram_tail2.c", mw_version="GC/1.2.5n"),
            Object(Matching, "OSSystemCall.c", mw_version="GC/1.2.5n"),
            Object(NonMatching, "OSThread.c", mw_version="GC/1.2.5n"),
            Object(Matching, "dolphin/os/OSThread_sched.c", mw_version="GC/1.2.5n"),
            Object(NonMatching, "dolphin/os/OSThread_queue.c"),
            Object(Matching, "dolphin/os/OSThread.c", mw_version="GC/1.2.5n"),
            Object(NonMatching, "dolphin/os/OSThreadQueue.c", mw_version="GC/1.2.5n"),
            Object(NonMatching, "dolphin/os/OSClearStack.c", mw_version="GC/1.2.5n"),
            Object(Matching, "dolphin/os/OSGetTime.c", mw_version="GC/1.2.5n"),
            Object(NonMatching, "dolphin/os/OSTime.c", mw_version="GC/1.2.5n"),
            Object(NonMatching, "dolphin/dvd/dvdlow.c", mw_version="GC/1.2.5n"),
            Object(NonMatching, "dolphin/dvd/dvdfs.c", mw_version="GC/1.2.5n"),
            Object(NonMatching, "dolphin/dvd/fstload.c", mw_version="GC/1.2.5n"),
            Object(NonMatching, "dolphin/vi/vi.c", mw_version="GC/1.2.5n"),
            Object(NonMatching, "dolphin/pad/Pad.c", mw_version="GC/1.2.5n"),
            Object(NonMatching, "auto/text_80216994.c", mw_version="GC/1.2.5n"),
            Object(Matching, "auto/CARDGetSerialNo.c", mw_version="GC/1.2.5n"),
            Object(Matching, "auto/CardFileAttr.c", mw_version="GC/1.2.5n"),
            Object(NonMatching, "auto/text_8021D7FC.c", mw_version="GC/1.2.5n"),
            Object(NonMatching, "auto/text_8022108C.c", mw_version="GC/1.2.5n"),
            Object(NonMatching, "auto/GXSetCopyFilter.c", mw_version="GC/1.2.5n"),
            Object(NonMatching, "auto/text_80221A2C.c", mw_version="GC/1.2.5n"),
            Object(NonMatching, "dolphin/gx/GXTexture.c", mw_version="GC/1.2.5n"),
            Object(NonMatching, "dolphin/gx/GXInitTexObjLOD.c", mw_version="GC/1.2.5n"),
            Object(NonMatching, "dolphin/gx/GXTexture2.c", mw_version="GC/1.2.5n"),
            Object(Matching, "dolphin/gx/GXTevOp.c", mw_version="GC/1.2.5n"),
            Object(NonMatching, "dolphin/gx/GXSetTevColor.c", mw_version="GC/1.2.5n"),
            Object(NonMatching, "dolphin/gx/GXSetTevColorS10.c", mw_version="GC/1.2.5n"),
            Object(NonMatching, "dolphin/gx/GXTexture_SU.c", mw_version="GC/1.2.5n"),
            Object(NonMatching, "dolphin/gx/GXTexture_rest.c", mw_version="GC/1.2.5n"),
            Object(Matching, "dolphin/gx/GXSetZCompLoc.c", mw_version="GC/1.2.5n"),
            Object(NonMatching, "dolphin/gx/GXTexture_rest2.c", mw_version="GC/1.2.5n"),
            Object(NonMatching, "dolphin/gx/GXSetProjection.c", mw_version="GC/1.2.5n"),
            Object(NonMatching, "dolphin/gx/GXLoadMtx.c", mw_version="GC/1.2.5n"),
            Object(NonMatching, "dolphin/gx/GXLoadMtxImm.c", mw_version="GC/1.2.5n"),
            Object(Matching, "dolphin/gx/GXLoadNrmMtxImm.c", mw_version="GC/1.2.5n"),
            Object(NonMatching, "dolphin/gx/GXGeometry.c", mw_version="GC/1.2.5n"),
            Object(NonMatching, "auto/text_80225E30.c"),
            Object(NonMatching, "auto/text_8022C518.c"),
            Object(NonMatching, "auto/text_8022CD68.c"),
            Object(Matching, "auto/text_8022E804.c", mw_version="GC/1.3"),
            Object(NonMatching, "auto/text_8022EBB8.c"),
            Object(NonMatching, "auto/text_80230944.c"),
            Object(NonMatching, "auto/text_80230BBC.c"),
            Object(NonMatching, "auto/text_80231CC8.c"),
            Object(NonMatching, "auto/text_80231D2C.c"),
            Object(NonMatching, "libm/e_pow.c"),
            Object(NonMatching, "auto/text_802387E8.c"),
            Object(NonMatching, "dolphin/exi/EXIBios.c", mw_version="GC/1.2.5n"),
            Object(NonMatching, "dolphin/si/SIBios.c", mw_version="GC/1.2.5n"),
            Object(Matching, "auto/text_8023C53C.c", mw_version="GC/1.2.5n"),
            Object(NonMatching, "auto/text_8023C56C.c", mw_version="GC/1.2.5n"),
            Object(Matching, "auto/text_8023C7B0.c", mw_version="GC/1.2.5n"),
            Object(NonMatching, "auto/text_8023C7F4.c", mw_version="GC/1.3.2"),
            Object(Matching, "auto/text_8023C930.c", mw_version="GC/1.2.5n"),
            Object(NonMatching, "auto/text_8023CA4C.c", mw_version="GC/1.2.5n"),
            Object(Matching, "auto/text_8023CFE8.c", mw_version="GC/1.2.5n"),
            Object(NonMatching, "auto/text_8023D0D8.c"),
            Object(NonMatching, "auto/text_8023D350.c", mw_version="GC/1.2.5n"),
            Object(NonMatching, "auto/adpcm_80243AD4.c"),
            Object(NonMatching, "auto/sound_80243FB8.c"),
            Object(NonMatching, "auto/text_80247D74.c"),
            Object(NonMatching, "auto/text_80249DD0.c"),
            Object(Matching, "auto/text_80255FB0.c"),
            Object(NonMatching, "auto/text_80256000.c"),
            Object(NonMatching, "dolphin/gba/GBA.c", mw_version="GC/1.2.5n"),
            Object(Matching, "auto/text_8026649C.c", mw_version="GC/1.2.5n"),
            Object(Matching, "auto/text_80266A5C.c", mw_version="GC/1.2.5n"),
            Object(NonMatching, "auto/text_80266D70.c"),
            Object(NonMatching, "text_80266F18.c", mw_version="GC/1.2.5n"),
            Object(NonMatching, "auto/text_80267458.c", mw_version="GC/1.2.5n"),
            Object(Matching, "auto/text_802677E4.c", mw_version="GC/1.2.5n"),
            Object(NonMatching, "auto/text_80006258.c"),
            Object(NonMatching, "auto/text_80011968.c"),
            Object(Matching, "auto/text_80016EE8.c"),
            Object(NonMatching, "auto/text_80019558.c"),
            Object(Matching, "auto/text_8001EE58.c"),
            Object(NonMatching, "auto/text_80028864.c"),
            Object(NonMatching, "auto/text_80033080.c"),
            Object(NonMatching, "auto/text_80055C70.c"),
            Object(NonMatching, "auto/text_8005A29C.c"),
            Object(NonMatching, "auto/text_8005ADE4.c"),
            Object(NonMatching, "auto/text_80072408.c"),
            Object(Matching, "auto/text_800732BC.c"),
            Object(NonMatching, "auto/text_80073E70.c"),
            Object(Matching, "auto/text_8007C534.c"),
            Object(NonMatching, "auto/text_8009F0BC.c"),
            Object(Matching, "auto/text_800A399C.c"),
            Object(Matching, "auto/text_800A39C4.c"),
            Object(NonMatching, "auto/text_800A9384.c"),
            Object(Matching, "auto/text_800AD1F4.c"),
            Object(NonMatching, "auto/text_800C3F18.c"),
            Object(NonMatching, "auto/text_801035C8.c"),
            Object(Matching, "auto/text_80105504.c"),
            Object(NonMatching, "auto/text_80110128.c"),
            Object(NonMatching, "auto/text_80120CC0.c"),
            Object(NonMatching, "auto/text_80127D80.c"),
            Object(Matching, "auto/text_8012C368.c"),
            Object(NonMatching, "auto/text_8013275C.c"),
            Object(NonMatching, "auto/text_80149F38.c"),
            Object(NonMatching, "auto/text_8014A25C.c"),
            Object(NonMatching, "auto/text_8014E350.c"),
            Object(NonMatching, "auto/text_801620BC.c"),
            Object(Matching, "auto/text_80183374.c"),
            Object(Matching, "auto/text_801A2AB4.c"),
            Object(Matching, "auto/text_801A7D3C.c"),
            Object(NonMatching, "auto/text_801AE2D4.c"),
            Object(Matching, "auto/text_801B3220.c"),
            Object(Matching, "auto/text_801E4380.c"),
            Object(NonMatching, "auto/text_801EA8C0.c"),
            Object(NonMatching, "auto/text_801F18D4.c"),
            Object(NonMatching, "auto/text_801FC620.c"),
            Object(NonMatching, "auto/text_8022C1E8.c"),
            Object(NonMatching, "auto/text_8022C260.c"),
            Object(NonMatching, "auto/text_8022C35C.c"),
            Object(NonMatching, "auto/text_8022C414.c"),
        ],
    },
]


# Optional callback to adjust link order. This can be used to add, remove, or reorder objects.
# This is called once per module, with the module ID and the current link order.
#
# For example, this adds "dummy.c" to the end of the DOL link order if configured with --non-matching.
# "dummy.c" *must* be configured as a Matching (or Equivalent) object in order to be linked.
def link_order_callback(module_id: int, objects: List[str]) -> List[str]:
    # Don't modify the link order for matching builds
    if not config.non_matching:
        return objects
    if module_id == 0:  # DOL
        return objects + ["dummy.c"]
    return objects


# Uncomment to enable the link order callback.
# config.link_order_callback = link_order_callback


# Optional extra categories for progress tracking
# Adjust as desired for your project
config.progress_categories = [
    ProgressCategory("game", "Game Code"),
    ProgressCategory("sdk", "SDK Code"),
]
config.progress_each_module = args.verbose
# Optional extra arguments to `objdiff-cli report generate`
config.progress_report_args = [
    # Marks relocations as mismatching if the target value is different
    # Default is "functionRelocDiffs=none", which is most lenient
    # "--config functionRelocDiffs=data_value",
]

if args.mode == "configure":
    # Write build.ninja and objdiff.json
    generate_build(config)
elif args.mode == "progress":
    # Print progress information
    calculate_progress(config)
else:
    sys.exit("Unknown mode: " + args.mode)
