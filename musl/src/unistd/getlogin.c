#ifndef SCC_TEST

#include <unistd.h>
#include <stdlib.h>

char *getlogin(void)
{
	return getenv("LOGNAME");
}
#endif
