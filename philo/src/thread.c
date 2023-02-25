#include "philo.h"

int	create_trhead(t_philo *philo, pthread_t *monitor)
{
	int	index;

	index = 0;
	philo->data->number_start = get_current();
	while (index < philo->data->number_philo)
	{
		if (pthread_create(&philo[index].thread, NULL, &dinner_philo,&philo[index]))
			return (printf(ERROR_THREAD), EXIT_FAILURE);
		index++;
	}
	if (pthread_create(monitor, NULL, &monitor_philo, philo))
		return (printf(ERROR_THREAD), EXIT_FAILURE);
	return (EXIT_SUCCESS);
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
