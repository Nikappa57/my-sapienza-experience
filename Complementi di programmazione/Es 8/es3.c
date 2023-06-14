#include "es8.h"

Insieme copy(Insieme s)
{
	IteratoreInsieme	it;
	Insieme				ins;

	it = creaIteratoreInsieme(s);
	ins = insiemeVuoto();
	while (hasNext(it))
		ins = inserisci(ins, next(it));
	return (ins);
}