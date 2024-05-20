#include "e3.h"
#include <stddef.h>
// La funzione my_strpbrk(s1, s2) deve restituire il puntatore alla prima 
// occorrenza in `s1` di un qualsiasi carattere presente nella stringa `s2` 
// oppure `NULL` se alcun carattere di s2 appare in `s1` prima che `s1` 
// stessa termini.

// scrivere la soluzione qui...

char *my_strpbrk(const char *s1, const char *s2)
{
	int i;
	for (;*s1; s1++)
		for (i = 0; s2[i]; i++)
			if (*s1 == s2[i])
				return (char *) s1;
	return (NULL);
}
