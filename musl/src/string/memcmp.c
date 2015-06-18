#include <string.h>

int musl_memcmp(const void *vl, const void *vr, size_t n)
{
	const unsigned char *l=vl, *r=vr;

#pragma rpcc cgra
	for (; n && *l == *r; n--, l++, r++);
	return n ? *l-*r : 0;
}
