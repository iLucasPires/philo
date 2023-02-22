#include "philo.h"

size_t	get_time_current(void)
{
	t_timeval	time;
	size_t		time_current;

	gettimeofday(&time, NULL);
	time_current = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (time_current);
}

size_t	get_time_difference(size_t time_start)
{
	size_t	time_current;

	time_current = get_time_current();
	return (time_current - time_start);
}
