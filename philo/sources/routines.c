#include "../includes/philo.h"

void	philo_eat(t_philo *philo)
{
	time_t	start;

	pthread_mutex_lock(&philo->table_info->forks[philo->left_id]);
	pthread_mutex_lock(&philo->table_info->forks[philo->right_id]);
	send_message(philo, PHILO_FORK);
	pthread_mutex_lock(&philo->eating_mutex);
	send_message(philo, PHILO_EAT);
	start = curr_time();
	while(curr_time() - start < philo->table_info->time_to_eat)
		usleep(25);
	pthread_mutex_unlock(&philo->table_info->forks[philo->left_id]);
	pthread_mutex_unlock(&philo->table_info->forks[philo->right_id]);
	pthread_mutex_unlock(&philo->eating_mutex);
}

void	philo_sleep(t_philo *philo)
{
	time_t	start;

	send_message(philo, PHILO_SLEEP);
	start = curr_time();
	while (curr_time() - start < philo->table_info->time_to_sleep)
		usleep(25);
	
}

// void	philo_think(t_philo *philo)
// {
// 	(void *)philo;
// }

void	*philo_routines(void *args)
{
	t_philo	*philo = (t_philo *)args;

	while(1)
	{
		philo_eat(philo);
		philo_sleep(philo);
		// philo_think(philo);
	}
	return(NULL);
}