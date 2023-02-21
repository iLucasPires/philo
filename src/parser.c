#include "philo.h"

t_number	is_number(char *str)
{
	long	number;
	int		sign;

	number = 0;
	sign = POSITIVE;
	while (*str == '+' || *str == '-')
	{
		if (*str++ == '-')
			sign *= NEGATIVE;
	}
	while (*str >= '0' && *str <= '9')
		number = number * 10 + (*str++ - '0');
	number *= sign;
	if (*str != '\0' || number > INT_MAX || number < INT_MIN)
		return ((t_number){FALSE, FALSE});
	return ((t_number){TRUE, (number)});
}

void	init_times(int argc, char **argv, t_data *data)
{
	t_number	number;

	number = is_number(argv[1]);
	if (number.is_number == FALSE || number.number < 2)
		exit_error(ERROR_NUMBER_PHILO);
	data->number_philo = number.number;
	while (argc-- > 2)
	{
		number = is_number(argv[argc]);
		if (number.is_number == FALSE || number.number < 1)
			exit_error(ERROR_ARGUMENTS);
		data->times[argc - 2] = number.number;
	}
	if (argv[5] == NULL)
		data->times[MUST_EAT] = -1;
}

void	check_args(int argc, char **argv, t_data *data)
{
	if (argc != 5 && argc != 6)
		exit_error("wrong number of arguments");
	init_times(argc, argv, data);
}
