#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <string.h>
# include <unistd.h>
# include <sys/time.h>

/*Messages*/
# define PHILO_FORK		100
# define PHILO_EAT		101
# define PHILO_SLEEP	102
# define PHILO_THINK	103
# define PHILO_DIED		104

typedef struct s_philo
{
	unsigned int	id;
	unsigned int	left_id;
	unsigned int	right_id;
	unsigned int	times_ate;
	pthread_t		routine_thread;
	pthread_t		death_tread;
	pthread_mutex_t	eating_mutex;
	struct s_table	*table_info;
	struct timeval	last_time_eat;	
}	t_philo;

typedef struct s_table
{
	int				philos_num;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				max_times_to_eat;
	int				alive;

	time_t			start_time;
	t_philo			**philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	msg_mutex;
}	t_table;

int		ft_atoi(const char *str);
int		ft_isnumber(const char *str);
int		try_init_table(int argc, char **argv, t_table *table);
void	philo_start(t_table *table);
void	deallocate_memory(t_table *table);
// int		try_start_philo_threads(t_table *table) //замени
time_t	curr_time();
void	*philo_routines(void *args);
void	send_message(t_philo *philo, int flag);


#endif