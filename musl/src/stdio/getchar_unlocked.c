#ifndef SCC_TEST

#include "stdio_impl.h"

int getchar_unlocked(void)
{
	return getc_unlocked(stdin);
}
#endif
