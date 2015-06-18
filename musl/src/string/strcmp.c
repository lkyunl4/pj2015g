#include <string.h>

int musl_strcmp(const char *l, const char *r)
{
  #pragma rpcc cgra
	for (; *l==*r && *l; l++, r++);
	return *(unsigned char *)l - *(unsigned char *)r;
}
