#include "e2A.h"

void reverseTextFile(const char *input_file, const char *output_file)
{
	FILE	*fin, *fout;
	int		file_len;
	char	*str;
	char	*line;
	char 	c;
	int 	i;
	int		n;

	if (!(fin = fopen(input_file, "r"))
		|| !(fout = fopen(output_file, "w")))
		return ;

	fseek(fin, 0L, SEEK_END);
	file_len = ftell(fin);
	fseek(fin, 0L, SEEK_SET);

	str = NULL;
	if (!(str = (char *) malloc(file_len + 1)))
		goto END;

	for (i = 0; (c = fgetc(fin)) != EOF; i++)
		str[i] = c;

	str[i] = '\0';
	while (i-- > 0)
	{
		while ((i > 0) && (str[i - 1] != '\n'))
			i--;
		fputs(str + i, fout);
		str[i] = '\0';
	}

END:
	fclose(fin);
	fclose(fout);
	if (str)
		free(str);
}

void reverseTextFile_ (const char *input_file, const char *output_file)
{
	FILE	*fin, *fout;
	char	str[1000];
	int		file_len;

	if (!(fin = fopen(input_file, "r"))
		|| !(fout = fopen(output_file, "w")))
		return ;
	fseek(fin, 0L, SEEK_END);
	file_len = ftell(fin);
	fseek(fin, 0L, SEEK_SET);

	while (file_len--)
		fputc('0', fout);

	while (fgets(str, sizeof(str), fin))
	{
		fseek(fout, -strlen(str), SEEK_CUR);
		fputs(str, fout);
		fseek(fout, -strlen(str), SEEK_CUR);
	}

	fclose(fin);
	fclose(fout);
}