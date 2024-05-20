#include "e1.h"

int	person_cmp(const person_t *p1, const person_t *p2)
{
	return (strcmp(p1->name, p2->name));
}

void sort_people(person_t p[], size_t nel)
{
	qsort(p, nel, sizeof(person_t), (int(*)(const void*, const void*))person_cmp);
}

int find_person_by_name(const void *name, const void *person)
{
	return strncmp(name, ((person_t *)person)->name, strlen(((person_t *)person)->name));
}

person_t *find_person(char *key, person_t sorted[], size_t n)
{
	return bsearch(key, sorted, n, sizeof(person_t), find_person_by_name);
}