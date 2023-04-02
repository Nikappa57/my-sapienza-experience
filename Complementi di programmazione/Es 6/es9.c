#include "fun.h"

void	filter_write(char *message, FILE *file)
{
	if (*message == '\0')
		return ;
	if (*message >= 'a' && *message <= 'z')
		fputs(*message, file);
	filter_write(message + 1, file);
}