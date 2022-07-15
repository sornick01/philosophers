#include "../includes/philo.h"

void	deallocate_memory(t_table *table)
{
	int i = 0;

	pthread_mutex_destroy(&table->msg_mutex);
	while (i < table->philos_num)
	{
		pthread_mutex_destroy(&table->philos[i]->eating_mutex);
		free(table->philos[i]);
		pthread_mutex_destroy(&table->forks[i]);
		++i;
	}
	free(table->forks);
	free(table->philos);
}