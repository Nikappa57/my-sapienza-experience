#ifndef __GET_CMD_LINE__
#define __GET_CMD_LINE__

#include <stdio.h>
#include <string.h>

#define MAX_LINE    1024
#define MAX_TOKENS  64
#define DELIM       " \t\n"

void get_cmd_line(char* argv[MAX_TOKENS]);

#endif


