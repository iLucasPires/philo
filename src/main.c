#include "philo.h"

t_philo	*init_philo(t_data *data)
{
	unsigned	index;
	t_philo		*philo;

	index = 0;
	printf("number_philo: %d\n", data->number_philo);
	philo = malloc(sizeof(t_philo) * data->number_philo);
	if (philo == NULL)
		exit_error("malloc failed");
	while (index < data->number_philo)
	{
		philo[index].id = index + 1;
		philo[index].data = data;
		index++;
	}
	return (philo);
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_philo	*philo;

	check_args(argc, argv, &data);
	philo = init_philo(&data);

	return (0);
}
