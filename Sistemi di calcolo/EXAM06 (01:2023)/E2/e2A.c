#include "e2A.h"

void decodeTextFile (const char *encoded_file, const char *key, char **decoded_text)
{
	FILE	*f;
	char	c;
	int		i;
	char	*key_str;
	long	file_len;

	if (!(f = fopen(key, "r")))
		return ;

	fseek(f, 0L, SEEK_END);
	file_len = ftell(f);
	fseek(f, 0L, SEEK_SET);

	i = 0;
	key_str = malloc(file_len);
	while ((c = fgetc(f)) != EOF)
		key_str[i++] = c;
	
	fclose(f);

	if (!(f = fopen(encoded_file, "r")))
	{
		fprintf(stderr, "Il file non esiste.\n");
		return ;
	}

	fseek(f, 0L, SEEK_END);
	file_len = ftell(f);
	fseek(f, 0L, SEEK_SET);

	if ((*decoded_text = (char *) malloc(file_len)) == NULL)
	{
		fprintf(stderr, "malloc error.\n");
		return ;
	}

	for (i = 0; (c = getc(f)) != EOF; i++)
	{
		if (c < 65 || c > 122)
			(*decoded_text)[i] = c;
		else
			(*decoded_text)[i] = key_str[c - 65];
	}

	(*decoded_text)[i] = '\0';
	fclose(f);
}
