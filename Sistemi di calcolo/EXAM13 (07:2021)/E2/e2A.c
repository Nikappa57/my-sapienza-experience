#include "e2A.h"

#include <stdio.h>


int	count_char(const char *s, const char c)
{
	int count;

	for (count = 0; *s && (*s != ' '); s++)
		if (*s == c)
			count++;
	return (count);
}

int	ft_strlen(const char *s)
{
	int count;

	for (count = 0; *s && (*s != ' '); s++)
		count++;
	return (count);
}

void	cpy_word(const char *text, char **word)
{
	int len = ft_strlen(text);
	if (*word)
		free(*word);
	*word = (char *) malloc(len + 1);
	assert(*word != NULL);
	memcpy(*word, text, len);
	(*word)[len] = '\0';
}

int wordWithMaxCount(const char* text, const char c, char ** word)
{
	int		max_count;
	int		count;
	char	*curr;
	char	*str;

	*word = NULL;
	str = strdup(text);
	curr = strtok(str, " ");
	for (max_count = 0; curr != NULL; curr = strtok(NULL, " "))
	{
		count = count_char(curr, c);
		if (count > max_count)
		{
			cpy_word(curr, word);
			max_count = count;
		}
	}

	return (max_count);
}