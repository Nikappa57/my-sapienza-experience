#include "e2A.h"

int loadStringsFromFile (const char * filename, char *** list)
{
	FILE	*f;
	int		i;
	char	buffer[1000];
	long	line_count;

	f = NULL;
	*list = NULL;
	if (!(f = fopen(filename, "r")))
		goto ERR;

	line_count = 0;
	while (fgets(buffer, 1000, f) != NULL)
	{
		if (isalpha(buffer[0]))
			line_count++;
	}

	(*list) = (char **) calloc(line_count, sizeof(char *));

	fseek(f, 0L, SEEK_SET);

	for (i = 0; fgets(buffer, 1000, f) != NULL; )
		if (isalpha(buffer[0]))
			(*list)[i++] = strdup(buffer);
	
	fclose(f);
	return (i);

ERR:
	if (f)
		fclose(f);
	i = 0;
	while (*list)
	{
		if ((*list)[i])
			free((*list)[i]);
		free(*list);
	}
	return (-1);
}
