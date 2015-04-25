#ifndef SCC_TEST

#ifndef SCC_TEST

#include <stdio.h>
#include <limits.h>

int vsprintf(char *restrict s, const char *restrict fmt, va_list ap)
{
	return vsnprintf(s, INT_MAX, fmt, ap);
}

#endif
#endif
