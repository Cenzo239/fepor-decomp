/* string pool for double2hex / printf float specials */
const char stringBase0_80282C60[] =
    "\0-INF\0-inf\0INF\0inf\0-NAN\0-nan\0NAN\0nan";
#define double2hex_strpool stringBase0_80282C60

/* Functions from 0x8022CD68 to 0x80267A7C, found by decomp-toolkit. */
#include "common.h"
typedef struct FileWriteState { u8 pad[4]; u8 reservedMode : 2; u8 mode : 3; u8 buffering : 2; u8 reservedFlag : 1; u8 pad5[3]; u8 state : 3; u8 reserved : 5; } FileWriteState;
typedef struct RuntimeDecimal { u8 sign; s16 exponent; u8 length; u8 digits[36]; } RuntimeDecimal;

static inline int msl_fflush(void *file) {
    s32 __flush_buffer(void *, s32 *);
    s32 __flush_all();
    s32 fn_80231748(void *);
    typedef struct {
        u8 pad[4];
        u16 pre:7;
        u16 ioMode:3;
        u16 rest:6;
    } FileWord4;
    typedef struct {
        u8 pad[4];
        u8 pre:2;
        u8 state:3;
        u8 rest:3;
    } FileByte4;
    typedef struct {
        u8 pad[8];
        u8 bufMode:3;
        u8 rest:4;
        u8 flag:1;
    } FileByte8;
    FileWord4 *w4 = (FileWord4 *)file;
    FileByte4 *b4 = (FileByte4 *)file;
    FileByte8 *b8 = (FileByte8 *)file;
    s32 pos;

    if (file == NULL) {
        return __flush_all();
    }
    if (((u8) M2C_FIELD(file, u8 *, 0xA) != 0) || (w4->ioMode == 0)) {
        return -1;
    }
    if (b4->state == 1) {
        return 0;
    }
    if (b8->bufMode >= 3U) {
        b8->bufMode = 2;
    }
    if (b8->bufMode == 2) {
        M2C_FIELD(file, s32 *, 0x28) = 0;
    }
    if (b8->bufMode != 1) {
        b8->bufMode = 0;
        return 0;
    }
    if (w4->ioMode != 1) {
        pos = 0;
    } else {
        pos = fn_80231748(file);
    }
    if (__flush_buffer(file, 0) != 0) {
        M2C_FIELD(file, u8 *, 0xA) = 1U;
        M2C_FIELD(file, s32 *, 0x28) = 0;
        return -1;
    }
    b8->bufMode = 0;
    M2C_FIELD(file, s32 *, 0x18) = pos;
    M2C_FIELD(file, s32 *, 0x28) = 0;
    return 0;
}

extern f32 lbl_80367068;
extern f64 lbl_8036BE20;
extern f64 lbl_8036BE28;
extern f64 lbl_8036BE30;
extern f64 lbl_8036BE38;
extern f64 lbl_8036BE40;
extern f64 lbl_8036BE48;
extern f64 lbl_8036BE50;
extern f64 lbl_8036BE58;
extern f64 lbl_8036BE60;
extern f64 lbl_8036BE68;
extern f64 lbl_8036BE70;
extern f64 lbl_8036BE78;
extern f64 lbl_8036BE80;
extern f64 lbl_8036BE88;
extern f64 lbl_8036BE90;
extern f64 lbl_8036BE98;
extern f64 lbl_8036BEA0;

extern f64 fn_80238A9C(f64, f64);

extern s32 lbl_80366F28;
extern char lbl_80282AE8[];
extern char lbl_80282B20[];
extern void *__stdio_exit;
extern void __close_all(void);
extern u8 gSoundData[];
extern f64 lbl_8036C368;
extern u16 Ecb_8033E188[192];u16 *D_80256B30;
extern s32 UART_Initialized;
extern f32 lbl_8036C374;
extern s32 gSynthTimeHi;
extern s32 gSynthTimeLo;
extern s32 gSynthSchedList;
extern s32 gSynthIdleList;
extern u32* lbl_80368A38;
extern void (*lbl_80368B34)(s16);
extern f32 lbl_8034C324[];
extern s32 D_80368AD0;
extern s32 lbl_80368B0C;
extern void (*__atexit_funcs[])(void);
extern s32 __atexit_curr_func;
extern void (*__console_exit)(void);
extern s32 __aborting;
extern void (*_dtors[])(void);
extern void _ExitProcess(void);
extern s16 lbl_802A1E90[];
extern u8 lbl_80368AAE;
extern u8 lbl_80368AAD;
extern u16 lbl_8035BF18[];
extern u32 lbl_8035C918[];

typedef struct __InStrCtrl {
    char *NextChar;
    s32 NullCharDetected;
} __InStrCtrl;

u32 fn_8026367C(void);
u16 Sound_GetChanParam(u8 arg0, u8 arg1, u8 arg2);
s32 __cvt_fp2unsigned(f32 arg0);
void Sound_SetVoiceEnvelope(u8 arg0, void *arg1, s32 arg2);
void fn_8026146C(s32 *);
void fn_8025FFC8(void *arg0, u8 arg1, s32 arg2, u8 arg3, u8 arg4, u8 arg5);
s32 Sound_LookupVid(void);
extern void func_80013934(s32 arg0);
extern s32 gSynthVoices;
extern u16 lbl_803548B8;
extern u16 lbl_80368A08;
extern u16 lbl_8035A510[];
extern u16 lbl_8035D118[256];
extern u16 gSoundChanParamsDefault[4288];
extern f32 lbl_802831BC[];
extern f64 lbl_8036C348;
extern u16 lbl_803670C0;
extern u32 lbl_803670C8;
extern u32 lbl_800000F8;

#include "musyx/select_source.h"

typedef struct Voice {
    u8 pad0[0x110];
    u64 flags;
    u8 pad118[0x5C];
    s32 unk174;
    s32 unk178;
    s32 unk17C;
    s32 unk180;
    s32 unk184;
    s32 unk188;
    u32 unk18C;
    u32 unk190;
} Voice;

typedef struct VidList {
    struct VidList *next; /* 0x0 */
    struct VidList *prev; /* 0x4 */
    u32 vid;              /* 0x8 */
    u32 root;             /* 0xC */
} VidList;

extern u32 vidGenerator;

static u32 GetNewVid(void) {
    u32 vid;

    do {
        vid = vidGenerator++;
    } while (vid == 0xFFFFFFFF);
    return vid;
}

typedef struct GroupData {
    u8 pad0[4];
    u16 id;     /* 0x04 */
    u16 type;   /* 0x06 */
    u8 pad8[0x1C - 0x8];
    u32 unk1C;  /* 0x1C */
    u32 unk20;  /* 0x20 */
    u32 unk24;  /* 0x24 */
} GroupData;

typedef struct GroupEntry {
    GroupData *data; /* 0x0 */
    u32 unk4;        /* 0x4 */
    u32 base;        /* 0x8 */
} GroupEntry;

typedef struct GroupNode {
    struct GroupNode *next; /* 0x0 */
    u32 unk4;               /* 0x4 */
    s16 count;              /* 0x8 */
    GroupEntry entries[1];  /* 0xC */
} GroupNode;

typedef struct GroupItem {
    u16 id;
    u8 pad2[0x52];
} GroupItem;

typedef struct SynthVoice {
    struct SynthVoice *next; /* 0x000 */
    struct SynthVoice *prev; /* 0x004 */
    u8 state;                /* 0x008 */
    u8 id;                   /* 0x009 */
    u16 unkA;                /* 0x00A */
    u32 vid;                 /* 0x00C */
    u8 pad10[0xF4 - 0x10];
    u32 unkF4;               /* 0x0F4 */
    struct VidList *unkF8;   /* 0x0F8 */
    struct VidList *unkFC;   /* 0x0FC */
    u8 pad100[0x11C - 0x100];
    s32 unk11C;              /* 0x11C */
    s32 unk120;              /* 0x120 */
    u8 pad124[0xEF0 - 0x124];
    s32 unkEF0;              /* 0xEF0 */
    s32 unkEF4;              /* 0xEF4 */
    u16 unkEF8;              /* 0xEF8 */
    u8 unkEFA;               /* 0xEFA */
    u8 padEFB[0x1508 - 0xEFB];
    struct {
        u8 pad0[0x32];
        u16 unk32;
        u8 pad34[4];
    } unk1508[16];           /* 0x1508 */
} SynthVoice;

typedef struct {
    char gpr;
    char fpr;
    char reserved[2];
    char *input_arg_area;
    char *reg_save_area;
} __va_list;
typedef __va_list va_list[1];

typedef struct {
    char *buffer;
    s32 length;
    s32 position;
} __OutStr;

s32 __pformatter(s32 (*)(void *, const char *, u32), void *, const char *, va_list);
s32 fn_80232220(void *, const char *, u32);

// The structure being used in functions in this file - assumed based on offset 0xF4
typedef struct {
    u8 unkF4;  // This is likely the member accessed in function with 0xF4 offset 
} SStructType;

void fn_8022CDD0(void *);
#pragma global_optimizer off
#pragma opt_strength_reduction off

#pragma opt_strength_reduction reset
#pragma global_optimizer reset

f64 fn_802380A8(f64, f64);

#pragma use_lmw_stmw on

extern s32 D_8022EF64;

#pragma global_optimizer off

#pragma global_optimizer reset

s32 fn_80230BBC(s32 arg0) {
    s32 temp_r4;

    temp_r4 = arg0 >> 0x1F;
    return (temp_r4 ^ arg0) - temp_r4;
}

s32 Abs(s32 arg0) {
    s32 temp_r4;

    temp_r4 = arg0 >> 0x1F;
    return (temp_r4 ^ arg0) - temp_r4;
}

/* Write any pending FILE buffer bytes via write_proc, then reset buffer pointers. */
s32 __flush_buffer(void *stream, s32 *nbytes) {
    typedef struct {
        void *handle;       /* 0x00 */
        u8 pad0[0x14];
        u32 position;       /* 0x18 file offset */
        u32 buffer;         /* 0x1C */
        u32 buffer_end;     /* 0x20 */
        u32 buffer_ptr;     /* 0x24 */
        u32 buffer_length;  /* 0x28 */
        u32 buffer_alignment; /* 0x2C */
        u8 pad1[4];
        u32 saved_position; /* 0x34 */
        u8 pad2[8];
        s32 (*write_proc)(void *, u32, u32 *, u32);  /* 0x40 */
        u8 pad3[4];
        u32 ref_con;        /* 0x48 */
    } FILE;
    FILE *file = (FILE *)stream;
    u32 n = file->buffer_ptr - file->buffer;
    s32 result;

    if (n != 0) {
        file->buffer_length = n;
        result = file->write_proc(file->handle, file->buffer, &file->buffer_length, file->ref_con);
        if (nbytes != NULL) {
            *nbytes = file->buffer_length;
        }
        if (result != 0) {
            return result;
        }
        file->position += file->buffer_length;
    }
    file->buffer_ptr = file->buffer;
    file->buffer_length = file->buffer_end;
    file->buffer_length = file->buffer_length - (file->position & file->buffer_alignment);
    file->saved_position = file->position;
    return 0;
}

void __prep_buffer(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x24) = (s32) M2C_FIELD(arg0, s32 *, 0x1C);
    M2C_FIELD(arg0, s32 *, 0x28) = (s32) M2C_FIELD(arg0, s32 *, 0x20);
    M2C_FIELD(arg0, s32 *, 0x28) = (s32) (M2C_FIELD(arg0, s32 *, 0x28) - (M2C_FIELD(arg0, s32 *, 0x18) & M2C_FIELD(arg0, s32 *, 0x2C)));
    M2C_FIELD(arg0, s32 *, 0x34) = (s32) M2C_FIELD(arg0, s32 *, 0x18);
}

void __end_critical_region(void) {

}

void __begin_critical_region(void) {

}

void __kill_critical_regions(void) {

}

s32 fn_80230CE0(s32 arg0) {
 extern u16 lbl_8029E9A8[256];
 if (arg0 == -1) return -1;
 return ((u8 *)lbl_8029E9A8)[(u8)arg0];
}

#pragma push
#pragma optimization_level 3
#pragma inline_depth(0)
u32 __fwrite(u32 arg0, u32 arg1, s32 arg2, void *arg3) {
    s32 __flush_buffer(void *, u32 *);
    u32 __memrchr(u32, s32, u32);
    M2C_UNK __stdio_atexit();
    s32 fseek(void *, M2C_UNK, M2C_UNK);
    s32 fwide(void *, M2C_UNK);
    void *memcpy(void *, const void *, u32);
    u32 sp8;
    s32 var_r31;
    u32 var_r30;
    u32 var_r29;
    s32 var_r28;
    s32 var_r3;
    u32 temp_r0;
    u32 temp_r0_2;
    u32 temp_r27;
    u32 temp_r31;
    u32 temp_r3_2;
    u32 temp_r4;
    u32 var_r27;
    u8 temp_r3;

    if (fwide(arg3, 0) == 0) {
        fwide(arg3, -1);
    }
    var_r29 = arg1 * arg2;
    if ((var_r29 == 0) || ((u8) M2C_FIELD(arg3, u8 *, 0xA) != 0) || (temp_r0 = ((u16) M2C_FIELD(arg3, u16 *, 4) >> 6U) & 7, ((temp_r0 == 0) != 0))) {
        return 0U;
    }
    if (temp_r0 == 2) {
        __stdio_atexit();
    }
    var_r31 = 1;
    var_r3 = 0;
    if (!(((u8) M2C_FIELD(arg3, u8 *, 5) >> 3U) & 1) || ((u32) (((u8) M2C_FIELD(arg3, u8 *, 4) >> 1U) & 3) == 2)) {
        var_r3 = 1;
    }
    if ((var_r3 == 0) && ((u32) (((u8) M2C_FIELD(arg3, u8 *, 4) >> 1U) & 3) != 1)) {
        var_r31 = 0;
    }
    if (!(((u8) M2C_FIELD(arg3, u8 *, 8) >> 5U) & 7)) {
        temp_r3 = ((FileWriteState *)arg3)->mode;
        if (temp_r3 & 2) {
            if ((temp_r3 & 4) && (fseek(arg3, 0, 2) != 0)) {
                return 0U;
            }
            ((FileWriteState *)arg3)->state = 1;
            __prep_buffer(arg3);
            goto block_20;
        }
    }
block_20:
    if ((u32) (((u8) M2C_FIELD(arg3, u8 *, 8) >> 5U) & 7) != 1) {
        M2C_FIELD(arg3, u8 *, 0xA) = 1U;
        M2C_FIELD(arg3, u32 *, 0x28) = 0U;
        return 0U;
    }
    var_r30 = arg0;
    var_r28 = 0;
    if ((var_r29 != 0) && ((temp_r4 = M2C_FIELD(arg3, u32 *, 0x24), temp_r3_2 = M2C_FIELD(arg3, u32 *, 0x1C), ((temp_r4 == temp_r3_2) == 0)) || (var_r31 != 0))) {
        M2C_FIELD(arg3, u32 *, 0x28) = (u32) (M2C_FIELD(arg3, u32 *, 0x20) - (temp_r4 - temp_r3_2));
loop_26:
        temp_r0_2 = M2C_FIELD(arg3, u32 *, 0x28);
        var_r27 = 0U;
        sp8 = temp_r0_2;
        if (temp_r0_2 > var_r29) {
            sp8 = var_r29;
        }
        if (((u32) (((u8) M2C_FIELD(arg3, u8 *, 4) >> 1U) & 3) == 1) && (sp8 != 0)) {
            var_r27 = __memrchr(var_r30, 0xA, sp8);
            if (var_r27 != 0U) {
                sp8 = (var_r27 + 1) - var_r30;
            }
        }
        if (sp8 != 0) {
            memcpy((void *)M2C_FIELD(arg3, u32 *, 0x24), (void *)var_r30, sp8);
            var_r30 += sp8;
            var_r28 += sp8;
            var_r29 -= sp8;
            M2C_FIELD(arg3, u32 *, 0x24) = (u32) (M2C_FIELD(arg3, u32 *, 0x24) + sp8);
            M2C_FIELD(arg3, u32 *, 0x28) = (u32) (M2C_FIELD(arg3, u32 *, 0x28) - sp8);
        }
        if ((((u32) M2C_FIELD(arg3, u32 *, 0x28) == 0) || (var_r27 != 0U) || !(((u8) M2C_FIELD(arg3, u8 *, 4) >> 1U) & 3)) && (__flush_buffer(arg3, NULL) != 0)) {
            M2C_FIELD(arg3, u8 *, 0xA) = 1U;
            var_r29 = 0;
            M2C_FIELD(arg3, u32 *, 0x28) = 0U;
        } else if ((var_r29 != 0) && (var_r31 != 0)) {
            goto loop_26;
        }
    }
    if ((var_r29 != 0) && (var_r31 == 0)) {
        temp_r27 = M2C_FIELD(arg3, u32 *, 0x1C);
        temp_r31 = M2C_FIELD(arg3, u32 *, 0x20);
        M2C_FIELD(arg3, u32 *, 0x1C) = var_r30;
        M2C_FIELD(arg3, u32 *, 0x20) = var_r29;
        M2C_FIELD(arg3, u32 *, 0x24) = (u32) (var_r30 + var_r29);
        if (__flush_buffer(arg3, &sp8) != 0) {
            M2C_FIELD(arg3, u8 *, 0xA) = 1U;
            M2C_FIELD(arg3, u32 *, 0x28) = 0U;
        }
        var_r28 += sp8;
        M2C_FIELD(arg3, u32 *, 0x1C) = temp_r27;
        M2C_FIELD(arg3, u32 *, 0x20) = temp_r31;
        __prep_buffer(arg3);
        M2C_FIELD(arg3, u32 *, 0x28) = 0U;
    }
    if ((u32) (((u8) M2C_FIELD(arg3, u8 *, 4) >> 1U) & 3) != 2) {
        M2C_FIELD(arg3, u32 *, 0x28) = 0U;
    }
    temp_r0 = arg1 - 1;
    return (var_r28 + temp_r0) / arg1;
}
#pragma pop
u32 fwrite(const void *ptr, u32 size, u32 count, void *stream)
{
    extern void __begin_critical_region(s32);
    extern void __end_critical_region(s32);
    extern u32 __fwrite(const void *, u32, u32, void *);

    u32 result;

    __begin_critical_region(2);

    result = __fwrite(ptr, size, count, stream);

    __end_critical_region(2);

    return result;
}

char *fn_8023108C(s32 value, char *p, u32 base) {
 s32 strlen(const char *);
 s8 negative;
 s32 length;
 s32 digit;
 s32 i;
 char temp;
 s32 j;
 char *buffer=p;
 negative=0; length=0;
 if(value<0) {value=-value; negative=1; p=buffer;}
 do {digit=(u32)value%base; if(digit>9) {length++; *p++=digit+0x37;} else {length++; *p++=digit+0x30;} value=(u32)value/base;} while(value!=0);
 if(negative) {buffer[length]='-'; length++;}
 buffer[length]=(i=0);
 j=strlen(buffer)-1;
 while(i<j) {temp=buffer[i]; buffer[i]=buffer[j]; buffer[j]=temp; i++; j--;}
 return buffer;
}

int fflush(void *file) {
    /* Flush a FILE's buffer to the device, or flush every open file when file is NULL. */
    s32 __flush_buffer(void *, s32 *);
    s32 __flush_all();
    s32 fn_80231748(void *);
    typedef struct {
        u8 pad[4];
        u16 pre:7;
        u16 ioMode:3;
        u16 rest:6;
    } FileWord4;
    typedef struct {
        u8 pad[4];
        u8 pre:2;
        u8 state:3;
        u8 rest:3;
    } FileByte4;
    typedef struct {
        u8 pad[8];
        u8 bufMode:3;
        u8 rest:4;
        u8 flag:1;
    } FileByte8;
    FileWord4 *w4 = (FileWord4 *)file;
    FileByte4 *b4 = (FileByte4 *)file;
    FileByte8 *b8 = (FileByte8 *)file;
    s32 pos;

    if (file == NULL) {
        return __flush_all();
    }
    if (((u8) M2C_FIELD(file, u8 *, 0xA) != 0) || (w4->ioMode == 0)) {
        return -1;
    }
    if (b4->state == 1) {
        return 0;
    }
    if (b8->bufMode >= 3U) {
        b8->bufMode = 2;
    }
    if (b8->bufMode == 2) {
        M2C_FIELD(file, s32 *, 0x28) = 0;
    }
    if (b8->bufMode != 1) {
        b8->bufMode = 0;
        return 0;
    }
    if (w4->ioMode != 1) {
        pos = 0;
    } else {
        pos = fn_80231748(file);
    }
    if (__flush_buffer(file, 0) != 0) {
        M2C_FIELD(file, u8 *, 0xA) = 1U;
        M2C_FIELD(file, s32 *, 0x28) = 0;
        return -1;
    }
    b8->bufMode = 0;
    M2C_FIELD(file, s32 *, 0x18) = pos;
    M2C_FIELD(file, s32 *, 0x28) = 0;
    return 0;
}

#pragma push
#pragma opt_propagation off
s32 fn_802312B0(void *arg0) {
    M2C_UNK fn_8022D014(s32);
    typedef struct {
        u8 pad[4];
        u16 pre:7;
        u16 mode:3;
        u16 rest:6;
    } S4;
    typedef struct {
        u8 pad[8];
        u8 mode:3;
        u8 flag:1;
        u8 rest:4;
    } B8;
    S4 *s4 = (S4 *)arg0;
    B8 *b8 = (B8 *)arg0;
    s32 flush_result;
    s32 close_result;
    long var_r3;

    if (arg0 == NULL) {
        return -1;
    }
    if (s4->mode == 0) {
        return 0;
    }
    flush_result = msl_fflush(arg0);
    close_result = M2C_FIELD(arg0, s32 (**)(s32), 0x44)(M2C_FIELD(arg0, s32 *, 0));
    s4->mode = 0;
    M2C_FIELD(arg0, s32 *, 0) = 0;
    if (b8->flag) {
        fn_8022D014(M2C_FIELD(arg0, s32 *, 0x1C));
    }
    var_r3 = 0;
    if ((flush_result) || (close_result)) {
        var_r3 = 1;
    }
    return (s32) (-var_r3 | var_r3) >> 0x1F;
}
#pragma pop
extern s32 fn_802314D8(s32, s32, s32);
s32 fseek(s32 arg0, s32 arg1, s32 arg2) {
extern void __begin_critical_region(s32);
extern void __end_critical_region(s32);
s32 result;
__begin_critical_region(2);
result = fn_802314D8(arg0, arg1, arg2);
__end_critical_region(2);
return result;
}

s32 fn_802314D8(s32 arg0, s32 arg1, s32 arg2) {
    extern s32 lbl_803687F0;
    s32 __flush_buffer(void *, s32 *);
    typedef struct {
        u8 pad[4];
        u16 pre:7;
        u16 mode:3;
        u16 rest:6;
    } S4;
    typedef struct {
        u8 pad[4];
        u8 pre:2;
        u8 modeB:3;
        u8 rest:3;
    } B4;
    typedef struct {
        u8 pad[8];
        u8 mode:3;
        u8 rest:5;
    } B8;
    S4 *s4;
    B4 *b4;
    B8 *b8;
    s32 offset;
    s32 whence;
    s32 i;
    s32 result;
    u8 *p;
    s32 n;
    s32 adj;
    s32 (*seek_proc)(s32, s32 *, s32, s32);

    s4 = (S4 *)arg0;
    b4 = (B4 *)arg0;
    b8 = (B8 *)arg0;
    whence = arg2;
    offset = arg1;

    if (s4->mode != 1 || M2C_FIELD(arg0, u8 *, 0xA) != 0) {
        lbl_803687F0 = 0x28;
        return -1;
    }

    if (b8->mode == 1) {
        if (__flush_buffer((void *)arg0, 0) != 0) {
            M2C_FIELD(arg0, u8 *, 0xA) = 1;
            M2C_FIELD(arg0, s32 *, 0x28) = 0;
            lbl_803687F0 = 0x28;
            return -1;
        }
    }

    if (whence == 1) {
        whence = 0;
        adj = 0;
        if ((s4->mode != 1 && s4->mode != 2) || M2C_FIELD(arg0, u8 *, 0xA) != 0) {
            result = -1;
            lbl_803687F0 = 0x28;
        } else if (b8->mode == 0) {
            result = M2C_FIELD(arg0, s32 *, 0x18);
        } else {
            p = (u8 *)M2C_FIELD(arg0, void **, 0x1C);
            n = (u8 *)M2C_FIELD(arg0, void **, 0x24) - p;
            result = M2C_FIELD(arg0, s32 *, 0x34) + n;
            if (b8->mode >= 3U) {
                adj = (s32)b8->mode - 2;
                result -= adj;
            }
            if (((*((u8 *)arg0 + 5) >> 3) & 1) == 0) {
                for (i = n - adj; i != 0; i--) {
                    if (*p++ == '\n') {
                        result++;
                    }
                }
            }
        }
        offset += result;
    }

    if (whence != 2 && b4->modeB != 3 && (b8->mode == 2 || b8->mode == 3)) {
        if ((u32)offset >= (u32)M2C_FIELD(arg0, s32 *, 0x18) ||
            (u32)offset < (u32)M2C_FIELD(arg0, s32 *, 0x34)) {
            b8->mode = 0;
        } else {
            M2C_FIELD(arg0, void **, 0x24) =
                (u8 *)M2C_FIELD(arg0, void **, 0x1C) + (offset - M2C_FIELD(arg0, s32 *, 0x34));
            M2C_FIELD(arg0, s32 *, 0x28) = M2C_FIELD(arg0, s32 *, 0x18) - offset;
            b8->mode = 2;
        }
    } else {
        b8->mode = 0;
    }

    if (b8->mode == 0) {
        seek_proc = (s32 (*)(s32, s32 *, s32, s32))M2C_FIELD(arg0, s32 *, 0x38);
        if (seek_proc != NULL) {
            if (seek_proc(M2C_FIELD(arg0, s32 *, 0), &offset, whence, M2C_FIELD(arg0, s32 *, 0x48)) != 0) {
                M2C_FIELD(arg0, u8 *, 0xA) = 1;
                M2C_FIELD(arg0, s32 *, 0x28) = 0;
                lbl_803687F0 = 0x28;
                return -1;
            }
        }
        M2C_FIELD(arg0, u8 *, 0x9) = 0;
        M2C_FIELD(arg0, s32 *, 0x18) = offset;
        M2C_FIELD(arg0, s32 *, 0x28) = 0;
    }
    return 0;
}

s32 fn_80231748(void *arg0) {
 void __begin_critical_region(s32);
 void __end_critical_region(s32);
 extern s32 errno;
 u8 *file=arg0;
 s32 result;
 u8 *p;
 s32 n;
 u32 mode;
 u32 state;
 s32 count;
 s32 adj;
 __begin_critical_region(2);
 adj=0;
 mode=(*(u16 *)(file+4)>>6)&7;
 if((mode!=1 && mode!=2)||file[10]!=0) { errno=40; result=-1; }
 else {
 state=(file[8]>>5)&7;
 if(state==0) result=*(s32 *)(file+0x18);
 else {
 p=*(u8 **)(file+0x1c);
 n=*(u8 **)(file+0x24)-p;
 result=n+*(s32 *)(file+0x34);
 if(state>=3) {adj=state-2; result-=adj;}
 if(!((file[5]>>3)&1)) { count=n-adj; while(count!=0) {if(*p++==10) result++; count--;}}
 }
 }
 __end_critical_region(2);
 return result;
}

static inline s32 __unicode_to_UTF8_helper(char *s, u32 wchar) {
    extern u32 lbl_8036BDF8;
    u32 prefixes = lbl_8036BDF8;
    s32 number_of_bytes;
    char *target_ptr;

    if (wchar < 0x80) {
        number_of_bytes = 1;
    } else if (wchar < 0x800) {
        number_of_bytes = 2;
    } else {
        number_of_bytes = 3;
    }

    target_ptr = s + number_of_bytes;
    switch (number_of_bytes) {
        case 3:
            *--target_ptr = (wchar & 0x3F) | 0x80;
            wchar = ((u16)wchar) >> 6;
        case 2:
            *--target_ptr = (wchar & 0x3F) | 0x80;
            wchar = ((u16)wchar) >> 6;
        case 1:
            *--target_ptr = wchar | ((u8 *)&prefixes)[number_of_bytes];
    }
    return number_of_bytes;
}

u32 wcstombs(char *dest, const u16 *src, u32 limit)
{
  char *Str_CopyPad(char *, const char *, s32);
  extern u32 lbl_8036BDF8;
  register const u16 *p;
  char buffer[3];
  u32 prefixes;
  s32 count;
  u32 total = 0;
  u32 ch;
  char *out;
  if ((dest == 0) || (src == 0))
  {
    return 0;
  }
  p = src;
  while (total <= limit)
  {
    ch = *p;
    if (ch == 0)
    {
      dest[total] = 0;
      break;
    }
    p++;
    prefixes = lbl_8036BDF8;
    if (ch < 0x80)
    {
      count = 1;
    }
    else
      if (ch < 0x800)
    {
      count = 2;
    }
    else
    {
      count = 3;
    }
    out = buffer + count;
    switch (count)
    {
      case 3:
        *(--out) = (ch & 0x3F) | 0x80;
        ch = ((u16) ch) >> 6;

      case 2:
        *(--out) = (ch & 0x3F) | 0x80;
        ch = ((u16) ch) >> 6;

      case 1:
        *(--out) = ch | ((u8 *) (&prefixes))[count];

    }

    if ((total + count) > limit)
    {
      break;
    }
    Str_CopyPad(dest + total, buffer, count);
    total += count;
  }

  return total;
}

int fn_80231944(const char *str1, const char *str2, int count) {
 const u8 *s1=(const u8*)str1-1;
 const u8 *s2=(const u8*)str2-1;
 int n=count+1;
 while (--n != 0) {
 if (*++s1 != *++s2) return *s1 < *s2 ? -1 : 1;
 }
 return 0;
}

void *__memrchr(void *arg0, int arg1, u32 arg2) {
    u32 value = (u8)arg1;
    u8 *ptr = (u8 *)arg0 + arg2;
    ++arg2;
    while (--arg2 != 0) {
        if (*--ptr == value) return ptr;
    }
    return NULL;
}

void *memchr(const void *ptr, int value, unsigned long count) {
    u32 c = (u8)value;
    const u8 *p = (const u8 *)ptr - 1;
    ++count;
    while (--count != 0) {
        if (*++p == c) return (void *)p;
    }
    return NULL;
}

void *memmove(void *dst, const void *src, u32 n) {
    void fn_80231B60(void *, const void *, u32);
    void fn_80231AB4(void *, const void *, u32);
    void fn_80231CC8(void *, const void *, u32);
    void fn_80231C20(void *, const void *, u32);
    const u8 *s;
    u8 *d;
    s32 rev;

    rev = (u32)src < (u32)dst;
    if (n >= 0x20U) {
        if (((u32)dst ^ (u32)src) & 3) {
            if (rev == 0) {
                fn_80231B60(dst, src, n);
            } else {
                fn_80231AB4(dst, src, n);
            }
        } else if (rev == 0) {
            fn_80231CC8(dst, src, n);
        } else {
            fn_80231C20(dst, src, n);
        }
        return dst;
    }
    if (rev == 0) {
        s = (const u8 *)src - 1;
        d = (u8 *)dst - 1;
        n += 1;
        while (--n != 0) {
            *++d = *++s;
        }
    } else {
        s = (const u8 *)src + n;
        d = (u8 *)dst + n;
        n += 1;
        while (--n != 0) {
            *--d = *--s;
        }
    }
    return dst;
}

typedef unsigned int uint;
typedef u32 size_t;
void fn_80231AB4(void *pDest, const void *pSrc, u32 len) {
    u32 i, v1, v2;
    uint src, ls, rs;
    ((u8 *)pSrc) = ((u8 *)pSrc) + len;
    ((u8 *)pDest) = ((u8 *)pDest) + len;
    i = ((u32)pDest) & 3;
    if (i != 0) {
        len -= i;
        do {
            *--((u8 *)pDest) = *--((u8 *)pSrc);
        } while (--i);
    }
    src = ((uint)(((u8 *)pSrc))) & 3;
    ls = src << 3;
    rs = 32 - ls;
    ((u8 *)pSrc) += 4 - src;
    i = len >> 3;
    v1 = *--((u32 *)pSrc);
    do {
        v2 = *--((u32 *)pSrc);
        *--((u32 *)pDest) = (v2 << ls) | (v1 >> rs);
        v1 = *--((u32 *)pSrc);
        *--((u32 *)pDest) = (v1 << ls) | (v2 >> rs);
    } while (--i);
    if (len & 4) {
        v2 = *--((u32 *)pSrc);
        *--((u32 *)pDest) = (v2 << ls) | (v1 >> rs);
    }
    len &= 3;
    if (len != 0) {
        ((u8 *)pSrc) += src;
        do {
            *--((u8 *)pDest) = *--((u8 *)pSrc);
        } while (--len);
    }
}

void fn_80231B60(void *dst, const void *src, u32 size) {
u32 *d;
u32 n, blocks;
const u8 *tail;
const u8 *sb;
u32 offset, shift, back;
u32 a,b;
u8 *db;
sb=(const u8*)src-1;
db=(u8*)dst-1;
n=(-(u32)dst)&3;
if(n) {
size-=n;
do { *++db=*++sb; } while(--n);
}
offset=(u32)(sb+1)&3;
d=(u32*)(db-3);
blocks=size>>3;
sb-=offset;
shift=offset*8;
back=32-shift;
a=*(const u32*)(sb+=1);
do {
b=*(const u32*)(sb+=4);
*++d=(a<<shift)|(b>>back);
a=*(const u32*)(sb+=4);
*++d=(b<<shift)|(a>>back);
} while(--blocks);
if(size&4) { b=*(const u32*)(sb+=4); *++d=(a<<shift)|(b>>back); }
size &=3;
tail=sb+3;
db=(u8*)d+3;
if(size) {
tail-=4-offset;
do { *++db=*++tail; } while(--size);
}
}

void fn_80231C20(u8 *dst, u8 *src, u32 n)
{
  u32 blocks;
  u8 *s;
  u32 new_var2;
  u8 *d;
  unsigned int i;
  u8 *new_var;
  s = src + n;
  d = dst + n;
  i = ((u32) d) & 3;
  if (i != 0)
  {
    n -= i;
    do
    {
      *(--d) = *(--s);
    }
    while (--i);
  }
  if ((blocks = n >> 5) != 0)
  {
    do
    {
      u32 b;
      u32 a;
      new_var = d - 4;
      a = *((u32 *) (s - 4));
      --blocks;
      ;
      new_var2 = *((u32 *) (s - 12));
      *((u32 *) new_var) = a;
      a = new_var2;
      if ((s && s) && s)
      {
      }
      *((u32 *) (d - 8)) = *((u32 *) (s - 8));
      b = *((u32 *) (s - 16));
      *((u32 *) (d - 12)) = a;
      a = *((u32 *) (s - 20));
      *((u32 *) (d - 16)) = b;
      b = *((u32 *) (s - 24));
      *((u32 *) (d - 20)) = a;
      a = *((u32 *) (s - 28));
      *((u32 *) (d - 24)) = b;
      b = *((u32 *) (s - 32));
      s -= 32;
      *((u32 *) (d - 28)) = a;
      d -= 32;
      *((u32 *) d) = b;
    }
    while (blocks != 0);
  }
  i = (n >> 2) & 7;
  if (i != 0)
  {
    do
    {
      s -= 4;
      --i;
      d -= 4;
      *((u32 *) d) = *((u32 *) s);
    }
    while (i != 0);
  }
  n &= 3;
  if (n != 0)
  {
    do
    {
      *(--d) = *(--s);
    }
    while (--n);
  }
}

#pragma optimization_level 3
