#include "e2A.h"

struct booking *new_elm(char name[], int places, char time[])
{
	struct booking *new;

	new = malloc(sizeof(struct booking));
	assert(new != NULL);
	new->next = NULL;
	new->places = places;
	new->surname = strdup(name);
	new->time = strdup(time);

	return (new);
}

void getLargeTables(struct booking ** list, const char * filename, int num)
{
	FILE			*f;
	char			buffer[BUFF_SIZE];
	char			name[N_SIZE + 1];
	char			places_str[P_SIZE + 1];
	int				places;
	char			time[T_SIZE + 1];
	int				i;
	struct booking	*curr;

	f = fopen(filename, "r");
	assert(f != NULL);
	*list = curr = NULL;
	while (fread(buffer, BUFF_SIZE, 1, f) > 0)
	{
		for (i = 0; (i < N_SIZE) && (buffer[i] != '_'); i++)
			name[i] = buffer[i];
		name[i] = '\0';

		for (i = 0; i < P_SIZE; i++)
			places_str[i] = buffer[N_SIZE + i];
		places_str[i] = '\0';

		places = atoi(places_str);

		for (i = 0; i < T_SIZE; i++)
			time[i] = buffer[N_SIZE + P_SIZE + i];
		time[i] = '\0';

		printf("name: %s, place: %d, time: %s\n", name, places, time );

		if (places < num)
			continue ;

		if (curr == NULL)
			curr = *list = new_elm(name, places, time);
		else
			curr = curr->next = new_elm(name, places, time);
	}
	fclose(f);

}