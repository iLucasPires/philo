#include "philo.h"

int	create_trhead(t_philo *philo, pthread_t *monitor)
{
	int	i;

	i = 0;
	philo->data->number_start = get_current();
	while (i < philo->data->number_philo)
	{
		if (pthread_create(&philo[i].thread, NULL, &dinner_philo, &philo[i]))
			return (EXIT_FAILURE);
		i++;
	}
	if (pthread_create(monitor, NULL, &monitor_philo, philo))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	join_thread(t_philo *philo, pthread_t *monitor)
{
	int	i;

	i = 0;
	while (i < philo->data->number_philo)
	{
		if (pthread_join(philo[i].thread, NULL))
			return (EXIT_FAILURE);
		i++;
	}
	if (pthread_join(*monitor, NULL))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

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
		philo[i].forks[LEFT] = &data->forks[philo[i].id % data->number_philo];
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
		if (create_trhead(philo, &monitor))
			return (printf(ERROR_THREAD), EXIT_FAILURE);
		if (join_thread(philo, &monitor))
			return (printf(ERROR_JOIN), EXIT_FAILURE);
	}
	destroy_data(&data);
	free(philo);
	return (EXIT_SUCCESS);
}
