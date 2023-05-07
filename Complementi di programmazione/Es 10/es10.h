#ifndef ES10_H
# define ES10_H

#include "coda.h"
#include "pila.h"
#include "string.h"

void	stampa_sequenza_inversa(void);
void	rimuovi_alcuni(Pila *p, const int *rimuovere, int n);
bool	check_palindrome(const char *s);
bool	check_palindrome_r(const char *s);
int*	rimuoviMinori(int *arr, int len, int *result_len);

void	stampa_sequenza(void);
int		elemento_iesimo(Coda *c, int pos);
void	avoid_stampa(Coda *c, int elem);
Coda	*coda_circolare(Coda *c, int n);
Coda	*elementi_pari(Coda *c);

#endif