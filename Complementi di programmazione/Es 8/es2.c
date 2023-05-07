#include "es8.h"

void	print(Insieme s)
{
	IteratoreInsieme	it;

	it = creaIteratoreInsieme(s);
	printf("{");
	while (hasNext(it))
		printf("%d%s", next(it), hasNext(it) ? ", " : "");
	printf("}\n");
	return ;
}

// void print(Insieme s) {
// 	IteratoreInsieme it = creaIteratoreInsieme(s);
// 	putchar('{');
// 	while (hasNext(it)) {
// 		printf("%d", next(it));
// 		if (hasNext(it)) {
// 			printf(", ");
// 		}
// 	}
// 	printf("}");
// }