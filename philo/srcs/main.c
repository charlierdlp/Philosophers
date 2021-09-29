#include "../includes/philo.h"

int create_threads(t_args *data, t_data *philos)
{
	int i;

	i = 0;
	while (i < data->total_philos)
	{
		if (pthread_create(&philos[i].thread, NULL, NULL, &philos[i]))
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_args	*data;
	t_data	*philos;

	if (!parse_args(argc, argv, data))
		return (1);
	if (!create_threads(data, philos))
		return (1);
}