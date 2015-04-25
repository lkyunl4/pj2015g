#ifndef SCC_TEST

#ifndef SCC_TEST

#include <sys/mman.h>
#include "syscall.h"

int mlock(const void *addr, size_t len)
{
	return syscall(SYS_mlock, addr, len);
}
#endif
#endif
