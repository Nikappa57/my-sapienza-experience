#ifndef ES8_H
# define ES8_H

#include "insf_scl.h"

Insieme	init(int *arr, int n);
void	print(Insieme s);
Insieme copy(Insieme s);
int		size(Insieme s);
bool	subset(Insieme a, Insieme b);
bool	equal(Insieme a, Insieme b);
Insieme	intersection(Insieme a, Insieme b);
Insieme	set_union(Insieme a, Insieme b);

#endif