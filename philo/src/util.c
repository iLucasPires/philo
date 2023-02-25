#include "philo.h"

int	strtoint(char *str)
{
	int	number;

	number = 0;
	while (*str == PLUS || *str == MINUS)
	{
		if (*str == MINUS)
			return (-1);
		str++;
	}
	while (*str >= '0' && *str <= '9')
		number = number * 10 + (*str++ - '0');
	if (*str != NULL_CHAR || number > INT_MAX)
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
	if (get_someone_dead(data))
		return ;
	pthread_mutex_lock(&data->control_print);
	while (amounts--)
		printf("%zu %d %s \n", get_diff(data->number_start), id, message);
	pthread_mutex_unlock(&data->control_print);
}
