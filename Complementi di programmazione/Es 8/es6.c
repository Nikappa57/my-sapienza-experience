#include "es8.h"

bool	equal(Insieme a, Insieme b)
{
	return (subset(a, b) && subset(b, a));
}