#include "e2.h"

static struct booking	*init_booking(char *surname, int places, char *time)
{
	struct booking	*result;

	if (!(result = (struct booking *) malloc(sizeof(*result))))
		return (NULL);
	result->surname = strdup(surname);
	result->places = places;
	result->time = strdup(time);
	result->next = NULL;
	return (result);
}

void	bookings_strncpy(char *dst, const char *src, size_t n)
{
	int i;

	for (i = 0; n-- && (src[i] != '\0') && (src[i] != '_'); i++)
		dst[i] = src[i];
	dst[i] = '\0';
}

void	print_list(struct booking *list)
{
	struct booking	*elm;

	elm = list;
	printf("LISTA:\n");
	while (elm)
	{
		printf("surname: %s, places: %d, time: %s\n", elm->surname, elm->places, elm->time);
		elm = elm->next;
	}
}


void getBookingsAfterTime(struct booking ** list, const char * data, int size, const char * time)
{
	struct booking	*elm;
	struct booking	*pos;
	char			surname[SURNAME_SIZE + 1];
	char			places[PLACES_SIZE + 1];
	char			time_str[TIME_SIZE + 1];

	*list = pos = NULL;
	for (int i = 0; i < size; i += RECORD_SIZE)
	{
		bookings_strncpy(surname, data + i, SURNAME_SIZE);

		bookings_strncpy(places, data + i + SURNAME_SIZE, PLACES_SIZE);

		bookings_strncpy(time_str, data + i + SURNAME_SIZE + PLACES_SIZE, TIME_SIZE);

		if (strcmp(time_str, time) >= 0)
		{
			if (!(elm = init_booking(surname, atoi(places), time_str)))
				return ;
			if (!pos)
				*list = pos = elm;
			else
				pos = pos->next = elm;
		}
	}
	// print_list(*list);
}

