/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_setter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpires-n <lpires-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 21:31:08 by lpires-n          #+#    #+#             */
/*   Updated: 2023/02/25 21:31:09 by lpires-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_last_meal_time(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->control);
	philo->last_meal_time = get_current();
	pthread_mutex_unlock(&philo->data->control);
}

void	set_number_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->control);
	philo->number_eat--;
	pthread_mutex_unlock(&philo->data->control);
}

void	set_data_number_eat(t_share *data)
{
	pthread_mutex_lock(&data->control);
	data->number_eat--;
	pthread_mutex_unlock(&data->control);
}

void	set_someone_dead(t_share *data)
{
	pthread_mutex_lock(&data->control);
	data->someone_dead = TRUE;
	pthread_mutex_unlock(&data->control);
}
