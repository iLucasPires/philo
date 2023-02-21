#include "philo.h"

void	check_args(int argc, char const *argv[])
{
	t_number	number;
	int			index;

	index = 0;
	if (argc != 5 && argc != 6)
	{
		printf("Error: wrong number of arguments (5 or 6 required)\n");
		exit(EXIT_FAILURE);
	}
	while (++index < argc)
	{
		number = is_number_within_range((char *)argv[index]);
		if (number.is_number == FALSE)
		{
			printf("Error: argument %d is not a number\n", index);
			exit(EXIT_FAILURE);
		}
		printf("number: %d \n", number.number);
	}
}

int	main(int argc, char const *argv[])
{
	t_data	data;

	(void)data;
	check_args(argc, argv);
	return (0);
}
