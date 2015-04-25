#ifndef SCC_TEST

#include <dirent.h>
#include "__dirent.h"

int dirfd(DIR *d)
{
	return d->fd;
}
#endif
