#include <philo.h>

void	get_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->forks[LEFT]);
	pthread_mutex_lock(philo->forks[RIGHT]);
	pthread_mutex_lock(&philo->data->control_print);
	philo->data->last_time = get_time_difference(philo->data->number_start);
	printf("%zu %d has taken a fork \n", philo->data->last_time, philo->id);
	printf("%zu %d has taken a fork \n", philo->data->last_time, philo->id);
	pthread_mutex_unlock(&philo->data->control_print);
}

void	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->control_print);
	philo->data->last_time = get_time_difference(philo->data->number_start);
	printf("%zu %d is eating \n", philo->data->last_time, philo->id);
	pthread_mutex_unlock(&philo->data->control_print);
	usleep(philo->data->times[TIME_TO_EAT]);
	pthread_mutex_unlock(philo->forks[LEFT]);
	pthread_mutex_unlock(philo->forks[RIGHT]);
}

void	sleeping(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->control_print);
	philo->data->last_time = get_time_difference(philo->data->number_start);
	printf("%zu %d is sleeping \n", philo->data->last_time, philo->id);
	pthread_mutex_unlock(&philo->data->control_print);
	usleep(philo->data->times[TIME_TO_SLEEP]);
}

void	thinking(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->control_print);
	philo->data->last_time = get_time_difference(philo->data->number_start);
	printf("%zu %d is thinking \n", philo->data->last_time, philo->id);
	pthread_mutex_unlock(&philo->data->control_print);
}

void	*dinner_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (philo->number_eat--)
	{
		get_forks(philo);
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}
