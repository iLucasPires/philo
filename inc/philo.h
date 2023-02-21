#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

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
	NEGATIVE = -1,
	POSITIVE = 1
};

enum
{
	TIME_TO_DIE,
	TIME_TO_EAT,
	TIME_TO_SLEEP,
	MUST_EAT
};

//------------------------------/
//			STRUCTURES			/
//------------------------------/
typedef struct timeval	t_timeval;

typedef struct s_number
{
	t_bool				is_number;
	int					number;
}						t_number;

typedef struct s_philo
{
	int					id;
	pthread_t			*thread;
}						t_philo;

typedef struct s_data
{
	size_t				times[4];
	unsigned			number_philo;
}						t_data;

size_t					get_time_current(void);
t_number				is_number_within_range(char *str);
#endif
