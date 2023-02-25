#include "philo.h"

static size_t	aux_monitor(t_philo *philo)
{
	size_t	diff;
	int		number_eat;

	diff = get_current() - get_last_meal_time(philo);
	number_eat = get_number_eat(philo);
	return (diff > philo->data->times[TIME_TO_DIE] && number_eat);
}

void	print_died(t_share *data, int id)
{
	pthread_mutex_lock(&data->control_print);
	printf("%zu %d died\n", get_diff(data->number_start), id);
	pthread_mutex_unlock(&data->control_print);
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
			set_someone_dead(philo->data);
			print_died(philo->data, philo[index].id);
			return (NULL);
		}
		index++;
		if (index == philo->data->number_philo)
			index = 0;
		usleep(1000);
	}
	return (NULL);
}
