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
