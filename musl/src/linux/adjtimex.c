#ifndef SCC_TEST

#include <sys/timex.h>
#include "syscall.h"

int adjtimex(struct timex *tx)
{
	return syscall(SYS_adjtimex, tx);
}
#endif
