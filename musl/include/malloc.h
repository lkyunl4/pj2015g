#ifndef _MALLOC_H
#define _MALLOC_H

#ifdef __cplusplus
extern "C" {
#endif

#define __NEED_size_t

#include <bits/alltypes.h>

void *musl_malloc (size_t);
void *calloc (size_t, size_t);
void *musl_realloc (void *, size_t);
void musl_free (void *);
void *valloc (size_t);
void *memalign(size_t, size_t);

size_t malloc_usable_size(void *);

#ifdef __cplusplus
}
#endif

#endif
