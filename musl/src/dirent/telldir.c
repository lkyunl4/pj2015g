#ifndef SCC_TEST

#include <dirent.h>
#include "__dirent.h"

long telldir(DIR *dir)
{
	return dir->tell;
}
#endif
