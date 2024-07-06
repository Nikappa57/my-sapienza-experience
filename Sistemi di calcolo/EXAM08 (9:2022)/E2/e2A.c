#include "e2A.h"

void getStudents(const char *filename, student *in_list, int min_mark)
{
	FILE	*f;

	if (!(f = fopen(filename, "w")))
		return ;

	while (in_list)
	{
		if (in_list->mark >= min_mark)
			fprintf(f, "%s %s - %d\n", in_list->surname, in_list->name, in_list->mark);
		in_list = in_list->next;
	}

	fclose(f);
}
