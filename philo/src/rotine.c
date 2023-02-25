#include "philo.h"

void	print_message(t_share *data, int id, char *message, int amounts)
{

	pthread_mutex_lock(&data->control_print);
	if (get_someone_dead(data))
	{
		pthread_mutex_unlock(&data->control_print);
		return ;
	}
	while (amounts--)
		printf("%zu %d %s \n", get_diff(data->number_start), id, message);
	pthread_mutex_unlock(&data->control_print);
}

static void	philo_get_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->forks[philo->id % 2 == 0]);
	pthread_mutex_lock(philo->forks[philo->id % 2 != 0]);
	print_message(philo->data, philo->id, "has taken a fork", 2);
}

static void	philo_eating(t_philo *philo)
{
	print_message(philo->data, philo->id, "is eating", 1);
	set_last_meal_time(philo);
	set_number_eat(philo);
	usleep(philo->data->times[TIME_TO_EAT]);
	pthread_mutex_unlock(philo->forks[LEFT]);
	pthread_mutex_unlock(philo->forks[RIGHT]);
}

static void	philo_sleeping_thinking(t_philo *philo)
{
	print_message(philo->data, philo->id, "is sleeping", 1);
	usleep(philo->data->times[TIME_TO_SLEEP]);
	print_message(philo->data, philo->id, "is thinking", 1);
}

void	*dinner_one_philo(t_philo *philo)
{
	print_message(philo->data, philo->id, "has taken a fork", 1);
	return (NULL);
}

void	*dinner_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	set_last_meal_time(philo);
	if (philo->data->number_philo == 1)
		return (dinner_one_philo(philo));
	while (philo->number_eat && !get_someone_dead(philo->data))
	{
		philo_get_forks(philo);
		philo_eating(philo);
		if (philo->number_eat == 0)
		{
			philo->data->number_eat--;
			return (NULL);
		}
		philo_sleeping_thinking(philo);
		usleep(1000);
	}
	return (NULL);
}
