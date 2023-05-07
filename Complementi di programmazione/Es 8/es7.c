#include "es8.h"

Insieme	intersection(Insieme a, Insieme b)
{
	IteratoreInsieme	it;
	Insieme				ins;
	T					val;

	ins = insiemeVuoto();
	it = creaIteratoreInsieme(a);
	while (hasNext(it))
	{
		val = next(it);
		if (membro(b, val))
			ins = inserisci(ins, val);
	}
	return (ins);
}