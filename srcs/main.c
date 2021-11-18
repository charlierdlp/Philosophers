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
	pthread_mutex_lock(&philo[right].fork);

	pthread_mutex_lock(&philo->table->write);
	printf("%llu %d is eating\n", get_time_ms(philo->table->current_time), philo->id);
	pthread_mutex_unlock(&philo->table->write);

	usleep(philo->table->time_eat);

	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo[right].fork);

}

void *start(void *data)
{
	t_philo *philo;

	philo = (t_philo*)data;

	if (philo->id % 2 == 0)
		usleep(1000);

	while (1)
	{
		ft_eat(philo);
	}
}

int create_threads(t_table *table)
{
	int i;

	i = 0;
	while (i < table->total_philos)
	{
		table->philo[i].table = table;
		if (pthread_create(&table->philo[i].thread, NULL, start, &table->philo[i]) != 0)
			return (0);
		i++;
	}
	i = 0;
	while (i < table->total_philos)
	{
		if (pthread_join(table->philo[i].thread, NULL) != 0)
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
int init_mutex(t_table *table)
{
	if (pthread_mutex_init(&table->write, NULL) != 0)
		return (0);
}

int init_philos(t_global *global)
{
	int i;

	i = 0;
	table->current_time = get_time_ms(0);
	init_mutex(table);

	while (i < table->total_philos)
	{
		if (pthread_mutex_init(&s_table->philo[i].fork, NULL))
			return (0);
		global->philo[i].id = i + 1;
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_table table;

	if (!parse_args(argc, argv, &table))
		return (1);

	table.philo = malloc(sizeof(t_philo) * ft_atoi(argv[1]));

	if (!table.philo)
		return (1);
	
	init_philos(&table);

	if (!create_threads(&table))
		return (1);
	
	printf("bien\n");
	return (0);
}