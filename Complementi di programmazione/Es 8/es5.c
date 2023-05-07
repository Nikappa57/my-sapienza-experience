#include "es8.h"


bool	subset(Insieme a, Insieme b)
{
	IteratoreInsieme	it;

	it = creaIteratoreInsieme(a);
	while (hasNext(it))
		if (!membro(b, next(it)))
			return (false);
	return (true);
}

bool subset_r_helper(IteratoreInsieme it, Insieme b)
{
	if (!hasNext(it))
		return (true);
	if (!membro(b, next(it)))
		return (false);
	return (subset_r_helper(it, b));
}

bool subset_r(Insieme a, Insieme b)
{
	return (subset_r_helper(creaIteratoreInsieme(a), b));
}