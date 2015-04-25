#ifndef SCC_TEST

#include <stdlib.h>
#include <wchar.h>
#include "libc.h"

wchar_t *wcsdup(const wchar_t *s)
{
	size_t l = wcslen(s);
	wchar_t *d = malloc((l+1)*sizeof(wchar_t));
	if (!d) return NULL;
	return wmemcpy(d, s, l+1);
}
#endif
