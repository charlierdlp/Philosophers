#include "../includes/philo.h"

void *talk()
{
	printf("hola\n");
}

void init_philos(t_args *args)
{
	args->total_philos = -1;
	args->time_die = -1;
	args->time_eat = -1;
	args->time_sleep = -1;
}

int create_threads(t_args *args, t_data *philos)
{
	int i;

	i = 0;
	while (i < args->total_philos)
	{
		if (pthread_create(&philos[i].thread, NULL, &talk, NULL))
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_args	args;
	t_data	philos;

	if (!parse_args(argc, argv, args))
		return (1);
	init_philos(args);
	if (!create_threads(args, philos))
		return (1);
	return (0);
}