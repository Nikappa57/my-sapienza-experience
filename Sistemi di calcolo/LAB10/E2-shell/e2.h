#ifndef __DO_SHELL__
#define __DO_SHELL__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>


#define MAX_LINE    1024
#define MAX_TOKENS  64
#define DELIM       " \t\n"

int do_shell(const char* prompt);

#endif

