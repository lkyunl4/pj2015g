#ifndef SCC_TEST

#include "libm.h"

double cabs(double complex z)
{
	return hypot(creal(z), cimag(z));
}
#endif
