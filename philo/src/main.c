#include "philo.h"

int	init_forks(t_share *data)
{
	int	i;

	i = 0;
	data->forks = calloc(data->number_philo, sizeof(pthread_mutex_t));
	while (i < data->number_philo)
	{
		if (pthread_mutex_init(&data->forks[i], NULL))
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

t_philo	*init_philo(t_share *data)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = calloc(data->number_philo, sizeof(t_philo));
	if (philo == NULL)
		return (NULL);
	if (init_forks(data))
		return (NULL);
	while (i < data->number_philo)
	{
		philo[i].id = i + 1;
		philo[i].data = data;
		philo[i].number_eat = data->number_eat;
		philo[i].forks[RIGHT] = &data->forks[philo[i].id - 1];
		philo[i].forks[LEFT] = &data->forks[philo[i].id
			% data->number_philo];
		i++;
	}
	data->number_eat = data->number_philo;
	return (philo);
}

int	main(int argc, char **argv)
{
	t_share		data;
	t_philo		*philo;
	pthread_t	monitor;

	if (init_share(argc, argv, &data))
	{
		printf(ERROR_ARGS);
		return (EXIT_FAILURE);
	}
	philo = init_philo(&data);
	if (philo != NULL)
	{
		create_trhead(philo, &monitor);
		join_thread(philo, &monitor);
	}
	destroy_data(&data);
	free(philo);
	return (EXIT_SUCCESS);
}
