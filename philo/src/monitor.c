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
	int		i;
	t_philo	*philo;

	i = 0;
	philo = (t_philo *)arg;
	while (get_data_number_eat(philo->data))
	{
		if (aux_monitor(&philo[i]))
		{
			set_someone_dead(philo->data);
			print_died(philo->data, philo[i].id);
			return (NULL);
		}
		i++;
		if (i == philo->data->number_philo)
			i = 0;
		usleep(1000);
	}
	return (NULL);
}
