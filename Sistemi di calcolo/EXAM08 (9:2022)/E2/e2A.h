#ifndef __E2__
#define __E2__

#include <stdio.h>
#include <stdlib.h>

typedef struct student {
	char surname[20]; 
	char name[20];
	int mark;
	struct student * next;
} student;

void getStudents(const char * filename, student * in_list, int min_mark);

#endif
