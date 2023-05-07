#include "es8.h"

int	size(Insieme s)
{
	IteratoreInsieme	it;
	int 				len;
	
	it = creaIteratoreInsieme(s);
	len = 0;
	for (; hasNext(it); len++, next(it));
	return (len);
}