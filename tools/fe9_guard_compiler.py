#!/usr/bin/env python3
"""Fail fast if FE9's problematic translation unit uses a compiler other than GC/1.3.2.

Called as a preflight from the generated Ninja MWCC compilation rule:
    python3 tools/fe9_guard_compiler.py COMPILER_PATH SOURCE [SOURCE ...]

Only the exact FE9 translation unit is restricted. All other files pass through.
"""

import pathlib
import sys

TARGET = "src/auto/text_8013CDCC.c"
REQUIRED_VERSION = "GC/1.3.2"


def is_target(source: str) -> bool:
    normalized = source.replace("\\", "/")
    # Permit ./src/... and absolute paths, but do not match similarly named files.
    return normalized == TARGET or normalized.endswith("/" + TARGET)


def main(args: list[str]) -> int:
    if len(args) < 2:
        print("FE9 compiler guard: expected COMPILER_PATH SOURCE [SOURCE ...]", file=sys.stderr)
        return 2

    compiler, *sources = args
    if not any(is_target(source) for source in sources):
        return 0

    # Don't trust configure.py: verify the compiler executable the Ninja rule
    # is actually about to launch. Normalizing separators also supports Wine paths.
    executable = pathlib.PurePosixPath(compiler.replace("\\", "/"))
    if (executable.name.lower() == "mwcceppc.exe"
            and len(executable.parts) >= 4
            and executable.parts[-3:] == ("GC", "1.3.2", "mwcceppc.exe")):
        return 0

    print(
        "\nFE9 COMPILER GUARD: BLOCKED a known problematic compilation.\n"
        f"  Source:   {TARGET}\n"
        f"  Compiler: {compiler}\n"
        f"  Required: {REQUIRED_VERSION}/mwcceppc.exe\n"
        "  Fix only this object's mw_version in configure.py, then run:\n"
        "      python3 configure.py\n"
        "  The compiler was NOT started. Other files remain unrestricted.\n",
        file=sys.stderr,
    )
    return 86


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
