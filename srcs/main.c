/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cruiz-de <cruiz-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 17:58:50 by cruiz-de          #+#    #+#             */
/*   Updated: 2021/12/03 19:47:54 by cruiz-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_eat(t_philo *philo)
{
	unsigned int	right;

	right = philo->id;
	if (right == (unsigned int)philo->table->total_philos)
		right = 0;
	pthread_mutex_lock(&philo->fork);
	ft_print(philo, FORKING);
	if (philo->table->total_philos == 1)
	{
		ft_usleep(philo->table->time_die);
		ft_print(philo, DEAD);
		philo->table->alive = 0;
		pthread_mutex_unlock(&philo->fork);
	}
	pthread_mutex_lock(&philo->table->philo[right].fork);
	ft_print(philo, FORKING);
	philo->last_meal = get_time_ms(philo->table->init_time);
	philo->count_meal += 1;
	ft_print(philo, EATING);
	ft_usleep(philo->table->time_eat);
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo->table->philo[right].fork);
}

void	ft_sleep(t_philo *philo)
{
	ft_print(philo, SLEEPING);
	ft_usleep(philo->table->time_sleep);
}

void	*start(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	if (philo->id % 2 == 0)
		usleep(1000);
	while (philo->table->alive)
	{
		ft_eat(philo);
		if (philo->count_meal == philo->table->max_meals)
		{
			philo->table->all_full = 1;
			break ;
		}
		ft_sleep(philo);
		ft_print(philo, THINKING);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_table	table;

	if (!parse_args(argc, argv, &table))
		return (1);
	table.philo = malloc(sizeof(t_philo) * ft_atoi(argv[1]));
	if (!table.philo)
		return (1);
	init_philos(&table);
	create_threads(&table);
	free(table.philo);
	return (0);
}
