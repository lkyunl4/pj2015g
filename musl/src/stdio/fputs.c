#include "stdio_impl.h"
#include <string.h>

int fputs(const char * s, FILE * f)
{
	return (int)fwrite(s, strlen(s), 1, f) - 1;
}

//weak_alias(fputs, fputs_unlocked);
