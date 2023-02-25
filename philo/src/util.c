#include "philo.h"

int	strtoint(char *str)
{
	int	number;

	number = 0;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			return (-1);
		str++;
	}
	while (*str >= '0' && *str <= '9')
		number = number * 10 + (*str++ - '0');
	if (*str != '\0' || number > 2147483647)
		return (-1);
	return (number);
}

size_t	get_current(void)
{
	t_timeval	time;
	size_t		time_current;

	gettimeofday(&time, NULL);
	time_current = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (time_current);
}

size_t	get_diff(size_t time_start)
{
	size_t	time_current;

	time_current = get_current();
	return (time_current - time_start);
}

void	print_message(t_share *data, int id, char *message, int amounts)
{
	pthread_mutex_lock(&data->control_print);
	if (get_someone_dead(data))
	{
		pthread_mutex_unlock(&data->control_print);
		return ;
	}
	while (amounts--)
		printf("%zu \t %d \t %s \n", get_diff(data->number_start), id, message);
	pthread_mutex_unlock(&data->control_print);
}
