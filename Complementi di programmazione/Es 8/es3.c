#include "es8.h"

void copy_helper(IteratoreInsieme it, Insieme *s)
{
	T val;

	if (hasNext(it))
	{
		val = next(it);
		copy_helper(it, s);
	}
	*(s) = inserisci(*(s), val);
}

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