#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "aux.h"

int occorrenze_lettera(const char s[], const char c) {
  if (*s == '\0')
      return (c == '\0');
  return (*s == c) + occorrenze_lettera(s + 1, c);
}


void occorrenze_alfabeto(const char s[], int v[]){
  
	for (int i = 0; i < 26; i++)
    	v[i] = occorrenze_lettera(s, 'a' + i);

  return;
}
