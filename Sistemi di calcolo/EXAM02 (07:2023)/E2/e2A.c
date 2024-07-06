#include "e2A.h"

int	count_vocals(const char *s)
{
	int	count;

	for (count = 0; s = strpbrk(s, "aeiouAEIOU"); s++)
		count++;
	return (count);
}

int vowelcount(const char** s, int n)
{
	pid_t	pid;
	int		result;
	int		status;

	if ((s == NULL) || (n == 0))
		return (-1);
	while (n--)
	{
		pid = fork();
		if (pid == -1)
			exit(EXIT_FAILURE);
		if (pid == 0)
			_exit(count_vocals(*s));
		s++;
	}
	for (result = 0; wait(&status) != -1; )
	{
		if (WIFEXITED(status))
			result += (WEXITSTATUS(status));
	}
	return (result);
}
