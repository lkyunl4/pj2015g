#ifndef SCC_TEST

#include <unistd.h>

int posix_close(int fd, int flags)
{
	return close(fd);
}
#endif
