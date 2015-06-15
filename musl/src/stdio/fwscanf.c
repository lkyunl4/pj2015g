#include <stdio.h>
#include <stdarg.h>
#include <wchar.h>
#include "libc.h"

int fwscanf(FILE * f, const wchar_t * fmt, ...)
{
	int ret;
	va_list ap;
	va_start(ap, fmt);
	ret = vfwscanf(f, fmt, ap);
	va_end(ap);
	return ret;
}

//weak_alias(fwscanf,__isoc99_fwscanf);
