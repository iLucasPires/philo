#ifndef PHILO_H
# define PHILO_H

//------------------------------/
//			LIBRARIES			/
//------------------------------/
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

//------------------------------/
//			CONSTANTS			/
//------------------------------/
# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define PLUS '+'
# define MINUS '-'
# define NULL_CHAR '\0'
# define ERROR_ARGS "wrong number of arguments"
# define ERROR_NUMBER "arguments must be numbers"
# define ERROR_NEGATIVE "arguments must be positive"
# define ERROR_THREAD "pthread_create failed"
# define ERROR_JOIN "pthread_join failed"
# define ERROR_MALLOC "malloc failed"

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
	unsigned			times[3];
	unsigned			number_eat;
	size_t				number_start;
	unsigned			number_philo;
	pthread_mutex_t		control_print;
	size_t				last_time;
	pthread_mutex_t		*forks;
	pthread_mutex_t		control;
}						t_data;

typedef struct s_philo
{
	unsigned			id;
	unsigned			number_eat;
	pthread_t			thread;
	t_data				*data;
	pthread_mutex_t		*forks[2];
}						t_philo;

//------------------------------/
//			FUNCTIONS			/
//------------------------------/
size_t					get_time_current(void);
size_t					get_time_difference(size_t time_start);
void					*dinner_philo(void *arg);
void					exit_error(char *message);
unsigned				strtoint(char *str);
void					launch_threads(t_philo *philo);
void					init_data(int argc, char **argv, t_data *data);
void					destroy_data(t_data *data);
#endif
