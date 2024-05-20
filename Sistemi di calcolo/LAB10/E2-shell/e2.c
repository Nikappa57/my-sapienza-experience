#include "e2.h"

void get_cmd_line(char* argv[])
{
	int		i;
	char	*tkn;
	char	str[MAX_LINE] = {0};

	if ((fgets(str, MAX_LINE, stdin) == NULL) || !*str)
	{
		*argv = NULL;
		return ;
	}
	tkn = strtok(str, DELIM);
	for (i = 0; (i < MAX_TOKENS) && tkn; i++)
	{
		argv[i] = strdup(tkn);
		tkn = strtok(NULL, DELIM);
	}
	argv[i] = NULL;
}

void free_argv(char* argv[]) {
	for (int i = 0; argv[i]; i++)
		free(argv[i]);
}

int	exe_cmd(char *argv[])
{
	int		pid;

	pid = fork();
	if (pid == -1)
	{
		perror("fork error");
		return (EXIT_FAILURE);
	}
	if (pid == 0)
	{
		if (execvp(argv[0], argv) == -1)
		{
			fprintf(stderr, "unknown command %s\n", argv[0]);
			exit(EXIT_FAILURE);
		}
		_exit(EXIT_FAILURE);
	}
	if (wait(NULL) == -1)
	{
		perror("wait error");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int do_shell(const char* prompt)
{
	char	*argv[MAX_TOKENS] = {NULL};

	while (42)
	{
		printf("%s", prompt);
		get_cmd_line(argv);
		if (!*argv)
			continue ;
		if (strncmp(argv[0], "quit", 5) == 0)
		{
			printf("quit!\n");
			break ;
		}
		if (exe_cmd(argv))
			return (free_argv(argv), EXIT_FAILURE);
		free_argv(argv);
	}
	free_argv(argv);
	return (EXIT_SUCCESS);
}
