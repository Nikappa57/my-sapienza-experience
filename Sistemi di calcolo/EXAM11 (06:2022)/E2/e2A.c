#include "e2A.h"

int	countchar(const char *s, char c)
{
	int	count = 0;

	while (*s)
		count += *s++ == c;
	return (count);
}

int multicount(const char** s, char c, int n)
{
	pid_t	pid;
	int		status;
	int		max_count;

	if ((s == NULL) || (n == 0) || (c == '\0'))
		return (-1);
	while (n-- > 0)
	{
		pid = fork();
		if (pid == -1)
			return (-1);
		if (pid == 0)
			_exit(countchar(*s, c));
		s++;
	}
	// printf("finish\n");
	max_count = 0;
	while ((pid = wait(&status)) > 0)
	{
		// printf("TERMINATO %d\n", pid);
		if (WIFEXITED(status))
		{
			if (WEXITSTATUS(status) > max_count)
				max_count = WEXITSTATUS(status);
		}
	}
	return (max_count);
}