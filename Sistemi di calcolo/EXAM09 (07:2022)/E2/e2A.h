#ifndef __E2__
#define __E2__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

# define BUFF_SIZE 37
# define N_SIZE 30
# define T_SIZE 5
# define P_SIZE 2

struct booking {
	char * surname;  //stringa
	int places;		 //intero
	char * time;     //stringa
	struct booking * next;
};

void getLargeTables(struct booking ** list, const char * filename, int num);

#endif
