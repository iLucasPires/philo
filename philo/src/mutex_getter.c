/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_getter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpires-n <lpires-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 21:31:01 by lpires-n          #+#    #+#             */
/*   Updated: 2023/02/25 21:31:03 by lpires-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	get_someone_dead(t_share *data)
{
	t_bool	ret;

	pthread_mutex_lock(&data->control);
	ret = data->someone_dead;
	pthread_mutex_unlock(&data->control);
	return (ret);
}

size_t	get_last_meal_time(t_philo *philo)
{
	size_t	ret;

	pthread_mutex_lock(&philo->data->control);
	ret = philo->last_meal_time;
	pthread_mutex_unlock(&philo->data->control);
	return (ret);
}

int	get_number_eat(t_philo *philo)
{
	int	ret;

	pthread_mutex_lock(&philo->data->control);
	ret = philo->number_eat;
	pthread_mutex_unlock(&philo->data->control);
	return (ret);
}

int	get_data_number_eat(t_share *data)
{
	int	ret;

	pthread_mutex_lock(&data->control);
	ret = data->number_eat;
	pthread_mutex_unlock(&data->control);
	return (ret);
}
