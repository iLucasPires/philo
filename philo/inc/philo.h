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
	t_bool				alive;
	size_t				last_meal_time;
	pthread_t			thread;
	t_share				*data;
	pthread_mutex_t		*forks[2];
}						t_philo;

typedef struct s_args
{
	t_share				*data;
	t_philo				*philo;
}						t_args;

//------------------------------/
//			FUNCTIONS			/
//------------------------------/
size_t					get_current(void);
size_t					get_diff(size_t time_start);
void					*dinner_philo(void *arg);
void					print_message(t_share *data, int id, char *message,
							int amounts);
void					*monitor_philo(void *arg);
void					exit_error(char *message);
int						strtoint(char *str);
void					launch_threads(t_philo *philo);
void					init_share(int argc, char **argv, t_share *data);
void					destroy_data(t_share *data);
int					create_trhead(t_philo *philo, pthread_t *monitor);
void					join_thread(t_philo *philo, pthread_t *monitor);
#endif
