#include "es8.h"

Insieme	set_union(Insieme a, Insieme b)
{
	IteratoreInsieme	it;
	Insieme				ins;
	T					val;

	it = creaIteratoreInsieme(b);
	ins = a;
	while (hasNext(it))
	{
		val = next(it);
		if (!membro(ins, val))
			ins = inserisci(ins, val);
	}
	return (ins);
}