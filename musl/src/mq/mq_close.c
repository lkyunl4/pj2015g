#ifndef SCC_TEST

#include <mqueue.h>
#include "syscall.h"

int mq_close(mqd_t mqd)
{
	return syscall(SYS_close, mqd);
}
#endif
