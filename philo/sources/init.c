#include "../includes/philo.h"


static int	check_args(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!ft_isnumber(argv[i]))
			return (0);
		if (ft_atoi(argv[i]) <= 0)
			return (0);
		++i;
	}
	return (1);
}

int	try_init_philos(t_table *table)
{
	int	i;

	i = 0;
	table->philos = (t_philo **)malloc(sizeof(t_philo *) * table->philos_num);
	if (!table->philos)
		return (0);
	while (i < table->philos_num)
	{
		table->philos[i] = (t_philo *)malloc(sizeof(t_philo));
		table->philos[i]->id = i;
		table->philos[i]->left_id = i;
		table->philos[i]->right_id = (i + 1) % (table->philos_num);
		table->philos[i]->table_info = table;
		table->philos[i]->times_ate = 0;
		if (pthread_mutex_init(&table->philos[i]->eating_mutex, NULL) != 0)
			return (0);
		++i;
	}
	return (1);
	
}

int	try_init_forks(t_table *table)
{
	int	i;

	table->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * table->philos_num);
	if (!table->forks)
		return (0);
	while (i < table->philos_num)
	{
		if(pthread_mutex_init(&(table->forks[i]), NULL) != 0)
			return (0);
		++i;
	}
	return (1);
}

int	try_init_table(int argc, char **argv, t_table *table)
{
	// table = (t_table *)malloc(sizeof(t_table));

	if (!check_args(argc, argv))
		return (0);
	if (argc != 5 && argc != 6)
		return (0);
	table = (t_table *)malloc(sizeof(t_table));
	if (!table)
		return (0);
	table->philos_num = ft_atoi(argv[1]);
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		table->max_times_to_eat = ft_atoi(argv[5]);
	else
		table->max_times_to_eat = -1;
	table->alive = 1;
	if (pthread_mutex_init(&table->msg_message, NULL) != 0)
		return(0);
	if (!try_init_philos(table))
		return (0);
	if (!try_init_forks(table))
		return (0);
	return (1);
}
