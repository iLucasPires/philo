#include "philo.h"

t_bool	get_someone_dead(t_share *data)
{
	t_bool	ret;

	pthread_mutex_lock(&data->control);
	ret = data->someone_dead;
	pthread_mutex_unlock(&data->control);
	return (ret);
}
