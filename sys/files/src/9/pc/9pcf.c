#include "u.h"
#include "../port/lib.h"
#include "mem.h"
#include "dat.h"
#include "fns.h"
#include "io.h"
#include "../port/error.h"

Dev* devtab[]={
	nil,
};

void (*i8237alloc)(void) = nil;
int i8237dma = 0;

void links(void){
	bootlinks();

}

PCArch* knownarch[] = {
	nil,
};

char* conffile = "/sys/src/9/pc/9pcf";
ulong kerndate = KERNDATE;
