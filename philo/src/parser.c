#include "philo.h"

int	*verify_args(int argc, char **argv)
{
	int	*args;
	int	i;

	i = 1;
	if (argc < 5 || argc > 6)
		return (NULL);
	args = malloc(sizeof(int) * (argc - 1));
	if (args == NULL)
		return (NULL);
	while (i < argc)
	{
		args[i - 1] = strtoint(argv[i]);
		if (args[i - 1] == -1)
		{
			free(args);
			return (NULL);
		}
		i++;
	}
	return (args);
}

int	init_share(int argc, char **argv, t_share *data)
{
	int	*args;

	args = verify_args(argc, argv);
	if (args == NULL)
		return (EXIT_FAILURE);
	data->number_philo = args[0];
	if (data->number_philo == 0)
	{
		free(args);
		return (EXIT_FAILURE);
	}
	data->times[TIME_TO_DIE] = args[1];
	data->times[TIME_TO_EAT] = args[2] * 1000;
	data->times[TIME_TO_SLEEP] = args[3] * 1000;
	data->number_eat = -1;
	if (argc == 6)
		data->number_eat = args[4];
	data->someone_dead = FALSE;
	pthread_mutex_init(&data->control_print, NULL);
	pthread_mutex_init(&data->control, NULL);
	free(args);
	return (EXIT_SUCCESS);
}

void	destroy_data(t_share *data)
{
	int	i;

	i = 0;
	while (i < data->number_philo)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&data->control_print);
	free(data->forks);
}
