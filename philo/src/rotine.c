#include "philo.h"

void	print_message(t_share *data, int id, char *message, int amounts)
{
	if (data->someone_dead)
		return ;
	pthread_mutex_lock(&data->control_print);
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
	pthread_mutex_lock(&philo->data->control);
	philo->last_meal_time = get_current();
	pthread_mutex_unlock(&philo->data->control);
	pthread_mutex_lock(&philo->data->control);
	philo->number_eat--;
	pthread_mutex_unlock(&philo->data->control);
	usleep(philo->data->times[TIME_TO_EAT]);
	pthread_mutex_unlock(philo->forks[LEFT]);
	pthread_mutex_unlock(philo->forks[RIGHT]);
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
	pthread_mutex_lock(&philo->data->control);
	philo->last_meal_time = get_current();
	pthread_mutex_unlock(&philo->data->control);
	if (philo->data->number_philo == 1)
		return (dinner_one_philo(philo));
	while (philo->number_eat && !philo->data->someone_dead)
	{
		philo_get_forks(philo);
		philo_eating(philo);
		if (philo->number_eat == 0)
		{
			philo->data->number_eat--;
			return (NULL);
		}
		print_message(philo->data, philo->id, "is sleeping", 1);
		usleep(philo->data->times[TIME_TO_SLEEP]);
		print_message(philo->data, philo->id, "is thinking", 1);
		usleep(1000);
	}
	return (NULL);
}
