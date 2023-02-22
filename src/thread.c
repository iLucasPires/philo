#include <philo.h>

void	create_trhead(t_philo *philo)
{
	unsigned	index;

	index = 0;
	philo->data->number_start = get_time_current();
	while (index < philo->data->number_philo)
	{
		if (pthread_create(&philo[index].thread, NULL, &dinner_philo,
				&philo[index]))
			exit_error(ERROR_THREAD);
		index++;
	}
}

void	join_thread(t_philo *philo)
{
	unsigned	index;

	index = 0;
	while (index < philo->data->number_philo)
	{
		if (pthread_join(philo[index].thread, NULL))
			exit_error(ERROR_JOIN);
		index++;
	}
}

void	launch_threads(t_philo *philo)
{
	create_trhead(philo);
	join_thread(philo);
}
