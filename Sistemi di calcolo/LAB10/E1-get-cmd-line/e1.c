#include "e1.h"

void get_cmd_line(char* argv[])
{
	int		i;
	char	*tkn;
	char	str[MAX_LINE];

	printf(">> ");
	if (fgets(str, MAX_LINE, stdin) == NULL)
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