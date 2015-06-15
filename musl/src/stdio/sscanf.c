#include <stdio.h>
#include <stdarg.h>
#include "libc.h"

int sscanf(const char * s, const char * fmt, ...)
{
	int ret;
	va_list ap;
	va_start(ap, fmt);
	ret = vsscanf(s, fmt, ap);
	va_end(ap);
	return ret;
}

//weak_alias(sscanf,__isoc99_sscanf);
