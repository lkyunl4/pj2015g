#ifndef SCC_TEST

#include <sys/uio.h>
#include "syscall.h"
#include "libc.h"

ssize_t readv(int fd, const struct iovec *iov, int count)
{
	return syscall_cp(SYS_readv, fd, iov, count);
}
#endif
