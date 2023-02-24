#include "philo.h"

void	exit_error(char *message)
{
	printf("Error: %s\n", message);
	exit(EXIT_FAILURE);
}

int	strtoint(char *str)
{
	int	number;

	number = 0;
	while (*str == PLUS || *str == MINUS)
	{
		if (*str == MINUS)
			exit_error(ERROR_NEGATIVE);
		str++;
	}
	while (*str >= '0' && *str <= '9')
		number = number * 10 + (*str++ - '0');
	if (*str != NULL_CHAR || number > INT_MAX)
		exit_error(ERROR_NUMBER);
	return (number);
}
