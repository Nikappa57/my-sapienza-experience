#ifndef ES6_H
#define ES6_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h> 

float	product(float vec[], int n);
void	vec_integral(float* v, int n);
int		length(char * s);
int		char_position(char *s, char ch);
int 	char_last_position(char* s, char ch);
bool	is_lowercase(char *s);
void	to_uppercase(char *s);
void	copy(char *dest, char *src);
void	concat(char *dest, const char *src);
void	filter_write(char *message, FILE *file);
bool	same_content(FILE *f1, FILE *f2);

#endif