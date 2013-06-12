#ifndef _UTIL_H_
#define _UTIL_H_

#include <unistd.h>

int set_affinity(int cpuid, pid_t pid);

#endif /*_UTIL_H_*/
