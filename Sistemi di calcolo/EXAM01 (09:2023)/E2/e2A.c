#include "e2A.h"

void run(int* v, int n, int (*f)(int i))
{
	pid_t	pid;

	for (int i = 0; i < n; ++i)
	{
		pid = fork();
		if (pid == -1)
			exit(1);
		if (pid == 0)
			_exit(f(i));
	}
	for (int ret, i = 0; wait(&ret) != -1; ++i)
		if (WIFEXITED(ret))
			v[i] = WEXITSTATUS(ret);
}
