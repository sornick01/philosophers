#include "../includes/philo.h"

int main(int argc, char **argv)
{
	t_table *table;

	void	*a = NULL;
	table = (t_table *)malloc(sizeof(t_table));
	if (!try_init_table(argc, argv, table))
		printf("huynya\n");
	else
		printf("OK\n");
	philo_start(table);
	pthread_join(table->philos[table->philos_num - 1]->routine_thread, &a);
}