#include "../includes/philo.h"

typedef enum estado = {
	UNINITIALIZED,
	EATING,
	SLEEPING,
	THINKING
} t_estado;



void *talk(void *mutex)
{
	t_estado e = EATING;

	if  (e == EATING)
	{
		
	}

	pthread_mutex_lock(mutex);

	printf("hola\n");
	  
	pthread_mutex_unlock(mutex);
	return (NULL);
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
	pthread_mutex_t *mutex;
	int i;

	i = 0;
	mutex = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(mutex, NULL);
	while (i < args->total_philos)
	{
		if (pthread_create(&philos[i].thread, NULL, &talk, mutex) != 0)
			return (0);
		printf("thread %d has started\n", i);
		i++;
	}
	i = 0;
	while (i < args->total_philos)
	{
		if (pthread_join(&philos[i].thread, NULL) != 0)
			return (0);
		printf("thread %d has finished\n", i);
		i++;
	}
	pthread_mutex_destroy(mutex);
	return (1);
}

int	main(int argc, char **argv)
{
	t_args	args;
	t_data	philos;

	if (!parse_args(argc, argv, &args))
		return (1);
	init_philos(&args);
	if (!create_threads(&args, &philos))
		return (1);
	printf("bien\n");
	return (0);
}