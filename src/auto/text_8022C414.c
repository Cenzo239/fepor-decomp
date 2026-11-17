// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include "common.h"

void *fn_8022C414(void *arg0, void (*ctor)(void *, s32), void (*dtor)(void *, s32), s32 size, u32 count) {
 struct { void *base; s32 size; u32 count; void (*dtor)(void *,s32); u32 index; } guard;
 register u8 *p;
 if(arg0 != NULL) {
 ((s32 *)arg0)[0]=size; ((u32 *)arg0)[1]=count;
 arg0=(u8 *)arg0+16;
 if(ctor != NULL) {
 guard.index=count; guard.base=arg0; guard.size=size; guard.count=count; guard.dtor=dtor; guard.index=0;
 p=arg0;
 while(guard.index<count) { ctor(p,1); p+=size; guard.index++; }
 if(guard.index<guard.count && guard.dtor!=NULL) {
 p=(u8 *)guard.base+guard.size*guard.index;
 while(guard.index!=0) {p-=guard.size;guard.dtor(p,-1);guard.index--;}
 }
 }
 }
 return arg0;
}
