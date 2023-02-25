#include "philo.h"

void	init_forks(t_share *data)
{
	int	index;

	index = 0;
	data->forks = calloc(data->number_philo, sizeof(pthread_mutex_t));
	while (index < data->number_philo)
	{
		if (pthread_mutex_init(&data->forks[index], NULL))
			exit_error(ERROR_THREAD);
		index++;
	}
}

t_philo	*init_philo(t_share *data)
{
	t_philo	*philo;
	int		index;

	index = 0;
	philo = calloc(data->number_philo, sizeof(t_philo));
	if (philo == NULL)
		exit_error(ERROR_MALLOC);
	init_forks(data);
	while (index < data->number_philo)
	{
		philo[index].id = index + 1;
		philo[index].data = data;
		philo[index].number_eat = data->number_eat;
		philo[index].forks[RIGHT] = &data->forks[philo[index].id - 1];
		philo[index].forks[LEFT] = &data->forks[philo[index].id
			% data->number_philo];
		index++;
	}
	data->number_eat = data->number_philo;
	return (philo);
}

int	main(int argc, char **argv)
{
	t_share		data;
	t_philo		*philo;
	pthread_t	monitor;

	init_share(argc, argv, &data);
	philo = init_philo(&data);
	create_trhead(philo, &monitor);
	join_thread(philo, &monitor);
	destroy_data(&data);
	free(philo);
	return (0);
}
