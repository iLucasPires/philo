/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpires-n <lpires-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 21:30:44 by lpires-n          #+#    #+#             */
/*   Updated: 2023/02/25 21:35:03 by lpires-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

//------------------------------/
//			LIBRARIES			/
//------------------------------/
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

//------------------------------/
//			CONSTANTS			/
//------------------------------/
# define ERROR_ARGS "wrong number of arguments or invalid arguments\n"
# define ERROR_THREAD "pthread_create failed\n"
# define ERROR_JOIN "pthread_join failed\n"
# define ERROR_MALLOC "malloc failed"

# define FORK "has taken a fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define DIED "died"

//------------------------------/
//			ENUMS				/
//------------------------------/
typedef enum e_bool
{
	FALSE,
	TRUE
}						t_bool;

enum
{
	TIME_TO_DIE,
	TIME_TO_EAT,
	TIME_TO_SLEEP
};

enum
{
	LEFT,
	RIGHT
};

//------------------------------/
//			STRUCTURES			/
//------------------------------/
typedef struct timeval	t_timeval;

typedef struct s_data
{
	size_t				times[3];
	int					number_eat;
	int					number_philo;
	size_t				number_start;
	t_bool				someone_dead;
	pthread_mutex_t		control_print;
	pthread_mutex_t		*forks;
	pthread_mutex_t		control;
}						t_share;

typedef struct s_philo
{
	int					id;
	int					number_eat;
	size_t				last_meal_time;
	pthread_t			thread;
	t_share				*data;
	pthread_mutex_t		*forks[2];
}						t_philo;

//------------------------------/
//			FUNCTIONS			/
//------------------------------/
size_t					get_current(void);
size_t					get_diff(size_t time_start);
void					my_usleep(size_t time);
void					*dinner_philo(void *arg);
void					print_message(t_share *data, int id, char *message, int amounts);
void					*monitor_philo(void *arg);
int						strtoint(char *str);
int						init_share(int argc, char **argv, t_share *data);
void					destroy_data(t_share *data);
int						create_trhead(t_philo *philo, pthread_t *monitor);
int						join_thread(t_philo *philo, pthread_t *monitor);

void					set_last_meal_time(t_philo *philo);
void					set_number_eat(t_philo *philo);
void					set_someone_dead(t_share *data);
void					set_data_number_eat(t_share *data);

int						get_data_number_eat(t_share *data);
t_bool					get_someone_dead(t_share *data);
size_t					get_last_meal_time(t_philo *philo);
int						get_number_eat(t_philo *philo);

#endif
