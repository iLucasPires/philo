#include "philo.h"

void	init_share(int argc, char **argv, t_share *data)
{
	if (argc != 5 && argc != 6)
		exit_error(ERROR_ARGS);
	data->number_philo = strtoint(argv[1]);
	data->times[TIME_TO_DIE] = strtoint(argv[2]);
	data->times[TIME_TO_EAT] = strtoint(argv[3]) * 1000;
	data->times[TIME_TO_SLEEP] = strtoint(argv[4]) * 1000;
	data->number_eat = -1;
	if (argc == 6)
		data->number_eat = strtoint(argv[5]);
	data->someone_dead = FALSE;
	pthread_mutex_init(&data->control_print, NULL);
	pthread_mutex_init(&data->control, NULL);
}

void	destroy_data(t_share *data)
{
	int	index;

	index = 0;
	while (index < data->number_philo)
	{
		pthread_mutex_destroy(&data->forks[index]);
		index++;
	}
	pthread_mutex_destroy(&data->control_print);
	free(data->forks);
}
