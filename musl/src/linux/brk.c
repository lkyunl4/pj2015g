#ifndef SCC_TEST

#include <errno.h>
#include "syscall.h"

int brk(void *end)
{
	return __syscall_ret(-ENOMEM);
}
#endif
