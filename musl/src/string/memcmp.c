#include <string.h>
#include <srp_vector.h>

#define __vec_equal(a, b) 
int musl_memcmp(const void *vl, const void *vr, size_t n)
{
/*
	const unsigned char *l=vl, *r=vr;
#pragma rpcc cgra
	for (; n && *l == *r; n--, l++, r++);
	return n ? *l-*r : 0;
*/

  long16* lvector = vl, *rvector = vr;
  long16 zeros = (long16)(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);
  size_t nqq;
  size_t nq = nqq = n / sizeof(long16);
  size_t nr = n % sizeof(long16);

  if(nq != 0) {
    nr += sizeof(long16);

    #pragma rpcc cgra
    for (; nq; nq--, lvector++, rvector++) {
      long16 ne =  (*lvector != *rvector);
      long* lptr = &ne;
      int i;
      for (i = 0; i < 16; i++, lptr++) {
        if (*lptr != 0) {
          goto done;
        }
      }
    }
  }
done:

  lvector--; rvector--;
	unsigned char *l=lvector, *r=rvector;

  #pragma rpcc cgra
	for (; nr && *l == *r; nr--, l++, r++);
	return nr ? *l-*r : 0;
}
