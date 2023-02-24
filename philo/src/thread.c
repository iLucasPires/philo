#include "philo.h"

void	create_trhead(t_philo *philo, pthread_t *monitor)
{
	int	index;

	index = 0;
	philo->data->number_start = get_current();
	while (index < philo->data->number_philo)
	{
		if (pthread_create(&philo[index].thread, NULL, &dinner_philo,
				&philo[index]))
			exit_error(ERROR_THREAD);
		index++;
	}
	if (pthread_create(monitor, NULL, &monitor_philo, philo))
		exit_error(ERROR_THREAD);
}

void	join_thread(t_philo *philo, pthread_t *monitor)
{
	int	index;

	index = 0;
	while (index < philo->data->number_philo)
	{
		if (pthread_join(philo[index].thread, NULL))
			exit_error(ERROR_JOIN);
		index++;
	}
	if (pthread_join(*monitor, NULL))
		exit_error(ERROR_JOIN);
}

void	launch_threads(t_philo *philo)
{
	pthread_t	monitor;

	create_trhead(philo, &monitor);
	join_thread(philo, &monitor);
}
