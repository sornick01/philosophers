#include "../includes/philo.h"

void	*philo_routine(void	*args)
{
	t_philo	*philo = (t_philo *)args;
	pthread_mutex_lock(&(philo->table_info->msg_mutex));
	for (int i = 0; i < 10; i++)
	{
		printf("i am philo %d %d\n", philo->id, i);
	}
	pthread_mutex_unlock(&(philo->table_info->msg_mutex));
	return (NULL);
}

int	try_start_philo_threads(t_table *table)
{
	int	i;

	i = 0;
	printf("%d\n", table->philos_num);
	printf("ok, lets try to start threads\n");
	while (i < table->philos_num)
	{
		// printf("try %d\n", i);
		if (pthread_create(&table->philos[i]->routine_thread, NULL, (void *)&philo_routine, (void *)table->philos[i]) != 0)
		{
			printf("pizdez\n");
			return (0);
		}
		pthread_detach(table->philos[i]->routine_thread);
		// printf("done %d\n", i);
		// usleep(100);
		++i;
	}
	return(1);
}

void	philo_start(t_table *table)
{
	if (!table)
		return ;
	if (!try_start_philo_threads(table))
		return ;
}
