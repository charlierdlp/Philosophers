#include "../includes/philo.h"
/*
typedef enum estado = {
	UNINITIALIZED,
	EATING,
	SLEEPING,
	THINKING
} t_estado;

	t_estado e = EATING;

	if  (e == EATING)
	{
		
	}

*/

void ft_eat(t_philo *philo)
{
	unsigned int right;

	right = philo->id;

	if (right == (unsigned int)philo->table->total_philos)
		right = 0;

	pthread_mutex_lock(&philo->fork);
	pthread_mutex_lock(&philo[right + 1].fork);
	printf("%lu %d is eating\n", get_time_ms(),philo->id);
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo[right + 1].fork);

}

void *start(void *data)
{
	t_philo *philo;

	philo = (t_philo*)data;

	//if (philo->id % 2)
	while (1)
	{
		ft_eat(philo);
	}
}

int create_threads(t_global *global)
{
	int i;

	i = 0;
	while (i < global->table.total_philos)
	{
		global->philo[i].table = &global->table;
		if (pthread_create(&global->philo[i].thread, NULL, start, &global->philo[i]) != 0)
			return (0);
		i++;
	}
	i = 0;
	while (i < global->table.total_philos)
	{
		if (pthread_join(global->philo[i].thread, NULL) != 0)
			return (0);
		i++;
	}
	return (1);
}
/*
int create_forks(t_args	*args, t_data *philos)
{
	int i;

	i = 0;
	philos->forks = malloc(args->total_philos * sizeof(pthread_mutex_t));
	while (i < args->total_philos)
	{
		if (pthread_mutex_init(&philos->forks[i], NULL)
			return (0);
		i++;
	}
	return (1);
}
*/
int init_mutex(t_global *global)
{
	pthread_mutex_init(&global->table.write, NULL);
	return (0);
}

int init_philos(t_global *global)
{
	int i;

	i = 0;
	init_mutex(global);
	while (i < global->table.total_philos)
	{
		if (pthread_mutex_init(&global->philo[i].fork, NULL))
			return (0);
		global->philo[i].id = i + 1;
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_global global;

	if (!parse_args(argc, argv, &global))
		return (1);

	global.philo = malloc(sizeof(t_global) * ft_atoi(argv[1]));

	if (!global.philo)
		return (1);
	
	init_philos(&global);

	if (!create_threads(&global))
		return (1);
	
	printf("bien\n");
	return (0);
}