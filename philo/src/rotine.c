#include "philo.h"

static void	philo_get_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->forks[philo->id % 2 == 0]);
	pthread_mutex_lock(philo->forks[philo->id % 2 != 0]);
	print_message(philo->data, philo->id, FORK, 2);
}

static void	philo_eating(t_philo *philo)
{
	print_message(philo->data, philo->id, EAT, 1);
	set_last_meal_time(philo);
	set_number_eat(philo);
	usleep(philo->data->times[TIME_TO_EAT]);
	pthread_mutex_unlock(philo->forks[LEFT]);
	pthread_mutex_unlock(philo->forks[RIGHT]);
}

static void	philo_sleeping_thinking(t_philo *philo)
{
	print_message(philo->data, philo->id, SLEEP, 1);
	usleep(philo->data->times[TIME_TO_SLEEP]);
	print_message(philo->data, philo->id, THINK, 1);
}

void	*dinner_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	set_last_meal_time(philo);
	if (philo->data->number_philo == 1)
	{
		print_message(philo->data, philo->id, "has taken a fork", 1);
		return (NULL);
	}
	while (philo->number_eat && !get_someone_dead(philo->data))
	{
		philo_get_forks(philo);
		philo_eating(philo);
		if (philo->number_eat == 0)
		{
			set_data_number_eat(philo->data);
			break ;
		}
		philo_sleeping_thinking(philo);
		usleep(1000);
	}
	return (NULL);
}
