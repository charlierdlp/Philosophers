/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cruiz-de <cruiz-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 20:23:14 by cruiz-de          #+#    #+#             */
/*   Updated: 2021/11/25 19:05:07 by cruiz-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	create_threads(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->total_philos)
	{
		table->philo[i].table = table;
		pthread_create(&table->philo[i].thread, NULL, start, &table->philo[i]);
		i++;
	}
	death_checker(table);
	i = 0;
	while (i < table->total_philos)
	{
		pthread_join(table->philo[i].thread, NULL);
		i++;
	}
	return (1);
}

int	init_mutex(t_table *table)
{
	pthread_mutex_init(&table->write, NULL);
	return (1);
}

int	init_philos(t_table *table)
{
	int	i;

	i = 0;
	table->init_time = get_time_ms(0);
	table->alive = 1;
	init_mutex(table);
	while (i < table->total_philos)
	{
		pthread_mutex_init(&table->philo[i].fork, NULL);
		table->philo[i].id = i + 1;
		i++;
	}
	return (1);
}
