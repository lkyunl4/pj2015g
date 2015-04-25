#ifndef SCC_TEST

#include "stdio_impl.h"

int __fclose_ca(FILE *f)
{
	return f->close(f);
}
#endif
