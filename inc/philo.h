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

# define ERROR_NUMBER_PHILO "number of philosophers must be greater than 1"
# define ERROR_ARGUMENTS "arguments must be greater than 0"

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

typedef struct s_data
{
	unsigned			times[4];
	unsigned			number_philo;
}						t_data;

typedef struct s_philo
{
	unsigned			id;
	t_data				*data;
}						t_philo;

//------------------------------/
//			FUNCTIONS			/
//------------------------------/
size_t					get_time_current(void);
void					exit_error(char *message);
void					check_args(int argc, char **argv, t_data *data);
#endif
