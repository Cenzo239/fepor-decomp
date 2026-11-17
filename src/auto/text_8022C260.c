// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include "common.h"

void fn_8022C260(void *base, void (*ctor)(void *, int), void (*dtor)(void *, int), u32 size, u32 count) {
struct { void *base; u32 size; u32 count; void (*dtor)(void *, int); u32 constructed; } guard;
char *p=base;
u32 i;
guard.base=base; guard.size=size; guard.count=count; guard.dtor=dtor; guard.constructed=count;
for(i=0;i<count;++i) { ctor(p,1); p+=size; guard.constructed=i+1; }
if(guard.constructed<guard.count && guard.dtor) {
p=(char *)guard.base+guard.size*guard.constructed;
while(guard.constructed) { p-=guard.size; guard.dtor(p,-1); --guard.constructed; }
}
}
