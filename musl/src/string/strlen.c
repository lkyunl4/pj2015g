#include <string.h>
#include <stdint.h>
#include <limits.h>

#define ALIGN (sizeof(size_t))
#define ONES ((size_t)-1/UCHAR_MAX)
#define HIGHS (ONES * (UCHAR_MAX/2+1))
#define HASZERO(x) ((x)-ONES & ~(x) & HIGHS)

size_t musl_strlen(const char *s)
{
	const char *a = s;
	const size_t *w;
  #pragma rpcc cgra
	for (; (uintptr_t)s % ALIGN; s++) if (!*s) return s-a;
  #pragma rpcc cgra
	for (w = (const void *)s; !HASZERO(*w); w++);
  #pragma rpcc cgra
	for (s = (const void *)w; *s; s++);
	return s-a;
}
