#include "philo.h"

t_number	is_number_within_range(char *str)
{
	int		sign;
	long	number;

	sign = POSITIVE;
	number = 0;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= NEGATIVE;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		number = number * 10 + (*str++ - '0');
	if (*str != '\0' || number > INT_MAX)
		return ((t_number){FALSE, FALSE});
	return ((t_number){TRUE, (sign * number)});
}
