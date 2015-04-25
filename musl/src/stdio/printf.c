#ifndef SCC_TEST

#ifndef SCC_TEST

#include <stdio.h>
#include <stdarg.h>

int printf(const char *restrict fmt, ...)
{
	int ret;
	va_list ap;
	va_start(ap, fmt);
	ret = vfprintf(stdout, fmt, ap);
	va_end(ap);
	return ret;
}

#endif
#endif
