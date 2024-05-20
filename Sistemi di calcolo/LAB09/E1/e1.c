#include "e1.h"

void	clear_person(person_t *p)
{
	if (!p)
		return ;
	if (p->surname)
		free(p->surname);
	if (p->name)
		free(p->name);
	free(p);
}

void	clear_person_lst(person_t **lst)
{
	person_t	*p;
	person_t	*tmp;

	if (!lst || !*lst)
		return ;
	p = *lst;
	while (p)
	{
		tmp = p->next;
		clear_person(p);
		p = tmp;
	}
	*lst = NULL;
}

person_t	*init_person(void)
{
	person_t	*p;

	p = (person_t *) malloc(sizeof(person_t));
	if (!p) goto ERR;
	p->name = NULL;
	p->surname = NULL;
	p->next = NULL;
	p->name = (char *) malloc(STR_SIZE);
	if (!p->name) goto ERR;
	p->surname = (char *) malloc(STR_SIZE);
	if (!p->surname) goto ERR;
	return (p);

ERR:
	return (clear_person(p), NULL);
}

int parseCSV(const char* file, person_t** out, int minYear) {
	FILE		*f;
	person_t	*p;
	person_t	*lst;
	char		phd[4];
	int			tmp;
	char		buff[LINE_SIZE + 1];

	lst = *out = NULL;
	if (!file || !*file || ((f = fopen(file, "r")) == NULL))
		return (-1);
	p = NULL;
	while (fgets(buff, LINE_SIZE, f))
	{
		p = init_person();
		if (!p) goto P_ERR;
		if (sscanf(buff,  "%49[^,],%49[^,],%d-%d-%d,%s\n", p->name, p->surname, &tmp, &tmp, &p->year, phd) != 6)
			goto P_ERR;
		p->has_phd = (int)(strcmp(phd, "yes") == 0);
		if (p->year >= minYear)
		{
			if (!*out)
				lst = *out = p;
			else
				lst = lst->next = p;
		}
		else
			clear_person(p);
		p = NULL;
	}
	fclose(f);
	return (0);

P_ERR:
	if (out)
		clear_person_lst(out);
	if (p)
		clear_person(p);
	fclose(f);
	return (-1);
}