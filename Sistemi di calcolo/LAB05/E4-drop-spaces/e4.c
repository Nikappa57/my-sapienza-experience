void drop_spaces(char* text)
{
	int i = -1, j = 0;

	do {
		if (text[++i] != ' ')
			text[j++] = text[i];
	} while (text[i]);
}