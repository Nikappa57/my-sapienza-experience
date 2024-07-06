#ifndef __E2__
#define __E2__

#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

void run(int* v, int n, int (*f)(int i));

#endif
