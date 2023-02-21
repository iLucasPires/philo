#include <philo.h>


void	*dinner_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	printf("philo %d is eating\n", philo->id);
	return (NULL);
}
