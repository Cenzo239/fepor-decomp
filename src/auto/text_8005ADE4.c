// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include "common.h"

void fn_8005ADE4(void)
{
  extern u8 lbl_80285C18[];
  extern u8 gUiIconDrawer[];
  extern u8 gItemIconDrawer[];
  extern u8 lbl_80285CCC[];
  extern u8 lbl_80285C84[];
  *((void **) (gUiIconDrawer + 0x44)) = lbl_80285C18;
  *((void **) (gUiIconDrawer + 0x44)) = lbl_80285CCC;
  *((void **) (gItemIconDrawer + 0x44)) = lbl_80285C18;
  *((void **) (gItemIconDrawer + 0x44)) = lbl_80285C84;
}
