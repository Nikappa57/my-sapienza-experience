#include "es8.h"

Insieme	init(int *arr, int n)
{
	Insieme ins;

	ins = insiemeVuoto();
	for (int i = 0; i < n; i++)
		ins = inserisci(ins, arr[i]);
	return (ins);	
}