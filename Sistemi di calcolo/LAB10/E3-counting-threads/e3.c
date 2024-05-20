#include <pthread.h>
#include <stdlib.h>

#include "e3.h"

void	*marius(void *arg)
{
	return (void *)(((thread_data_t *)arg)->it * ((thread_data_t *)arg)->val);
}

unsigned int counting_threads(unsigned int th, unsigned int it, unsigned int val)
{
	thread_data_t	data = {it, val};
	int				sum = 0;
	void			*ret;
	pthread_t		threads[th];

	for (int i = 0; i < th; i++)
		pthread_create(&threads[i], NULL, marius, &data);
	for (int i = 0; i < th; i++)
	{
		pthread_join(threads[i], &ret);
		sum += (int)ret;
	}
	return (sum);
}