#ifndef SCC_TEST

#ifndef SCC_TEST

#include <stdio.h>

int vprintf(const char *restrict fmt, va_list ap)
{
	return vfprintf(stdout, fmt, ap);
}

#endif
#endif
