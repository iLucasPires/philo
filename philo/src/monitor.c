#include "philo.h"

static size_t	aux_monitor(t_philo *philo)
{
	size_t	diff;
	int		number_eat;

	pthread_mutex_lock(&philo->data->control);
	diff = get_current() - philo->last_meal_time;
	pthread_mutex_unlock(&philo->data->control);
	pthread_mutex_lock(&philo->data->control);
	number_eat = philo->number_eat;
	pthread_mutex_unlock(&philo->data->control);
	return (diff > philo->data->times[TIME_TO_DIE] && number_eat);
}

void	*monitor_philo(void *arg)
{
	int		index;
	t_philo	*philo;

	index = 0;
	philo = (t_philo *)arg;
	while (philo->data->number_eat)
	{
		if (aux_monitor(&philo[index]))
		{
			print_message(philo->data, philo[index].id, "died", 1);
			philo->data->someone_dead = TRUE;
			return (NULL);
		}
		index++;
		if (index == philo->data->number_philo)
			index = 0;
		usleep(1000);
	}
	return (NULL);
}
