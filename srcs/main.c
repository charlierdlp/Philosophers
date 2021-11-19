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
	pthread_mutex_lock(&philo->table->write);
	printf("%llu %d has taken a fork\n", get_time_ms(philo->table->current_time), philo->id);
	pthread_mutex_unlock(&philo->table->write);

	pthread_mutex_lock(&philo->table->philo[right].fork);
	pthread_mutex_lock(&philo->table->write);
	printf("%llu %d has taken a fork\n", get_time_ms(philo->table->current_time), philo->id);
	pthread_mutex_unlock(&philo->table->write);

	pthread_mutex_lock(&philo->table->write);
	printf("%llu %d is eating\n", get_time_ms(philo->table->current_time), philo->id);
	pthread_mutex_unlock(&philo->table->write);

	ft_usleep(philo->table->time_eat);

	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo->table->philo[right].fork);

}

void ft_sleep(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->write);
	printf("%llu %d is sleeping\n", get_time_ms(philo->table->current_time), philo->id);
	pthread_mutex_unlock(&philo->table->write);

	ft_usleep(philo->table->time_sleep);
}

void ft_think(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->write);
	printf("%llu %d is thinking\n", get_time_ms(philo->table->current_time), philo->id);
	pthread_mutex_unlock(&philo->table->write);
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
		ft_sleep(philo);
		ft_think(philo);
	}
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

	return (0);
}