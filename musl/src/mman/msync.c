#ifndef SCC_TEST

#ifndef SCC_TEST

#include <sys/mman.h>
#include "syscall.h"

int msync(void *start, size_t len, int flags)
{
	return syscall_cp(SYS_msync, start, len, flags);
}
#endif
#endif
