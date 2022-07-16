#include "../includes/philo.h"

int main(int argc, char **argv)
{
	t_table table;

	// void	*a = NULL;
	if (!try_init_table(argc, argv, &table))
		printf("huynya\n");
	else
	{
		printf("OK\n");
		printf("after init philos_num = %d\n", table.philos_num);
		philo_start(&table);
		// for (int i = 0; i < philos_num; i++)
		// {
		// 	pthread_join(table.philos[table.philos_num - 1]->routine_thread, NULL);
		// }
		// usleep(3000000);	
		// deallocate_memory(&table);
		while (1)
		{
			/* code */
		}
		
	}
	curr_time();
}