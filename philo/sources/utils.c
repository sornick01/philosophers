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

time_t	curr_time()
{
	struct timeval	tv;
	time_t			time;

	gettimeofday(&tv, NULL);	
	time = (tv.tv_sec * 1000000 + tv.tv_usec) / 1000;
	// printf("timeval: %ld, %ld\n%ld\n", tv.tv_sec, tv.tv_usec, time);
	return time;
}

void	send_message(t_philo *philo, int flag)
{
	time_t	timestamp;

	timestamp = curr_time() - philo->table_info->start_time;
	if (flag == PHILO_FORK)
		printf("%ld %d has taken a fork\n", timestamp, philo->id + 1);
	else if (flag == PHILO_EAT)
		printf("%ld %d is eating\n", timestamp, philo->id + 1);
	else if (flag == PHILO_SLEEP)
		printf("%ld %d is sleeping\n", timestamp, philo->id + 1);
	else if (flag == PHILO_THINK)
		printf("%ld %d is thinking\n", timestamp, philo->id + 1);
	else if (flag == PHILO_DIED)
		printf("%ld %d died\n", timestamp, philo->id + 1);
}