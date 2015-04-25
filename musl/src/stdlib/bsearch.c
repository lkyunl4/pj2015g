#ifndef SCC_TEST

#include <stdlib.h>

void *bsearch(const void *key, const void *base, size_t nel, size_t width, int (*cmp)(const void *, const void *))
{
	void *try;
	int sign;
	while (nel > 0) {
		try = (char *)base + width*(nel/2);
		sign = cmp(key, try);
		if (!sign) return try;
		else if (nel == 1) break;
		else if (sign < 0)
			nel /= 2;
		else {
			base = try;
			nel -= nel/2;
		}
	}
	return NULL;
}
#endif
