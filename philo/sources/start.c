#include "../includes/philo.h"

void	*philo_routine(void	*args)
{
	t_philo	*philo = (t_philo *)args;
	pthread_mutex_lock(&philo->table_info->msg_message);
	printf("i am philo %d\n", philo->id);
	pthread_mutex_unlock(&philo->table_info->msg_message);
	return (NULL);
}

int	try_start_philo_threads(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->philos_num)
	{
		pthread_create(&table->philos[i]->routine_thread, NULL, (void *)philo_routine, (void *)table->philos[i]);
		++i;
	}
	return(1);
}

void	philo_start(t_table *table)
{
	try_start_philo_threads(table);
}


