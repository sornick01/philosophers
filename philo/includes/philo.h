#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <string.h>
# include <unistd.h>

typedef struct s_philo
{
	unsigned int	id;
	unsigned int	left_id;
	pthread_mutex_t	eating_mutex;
	pthread_mutex_t	message_mutex;

};

typedef struct s_table
{
	unsigned int	philos_num;
	unsigned int	time_to_eat;
};



#endif