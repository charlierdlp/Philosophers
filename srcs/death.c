/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cruiz-de <cruiz-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:33:09 by cruiz-de          #+#    #+#             */
/*   Updated: 2021/12/02 19:48:34 by cruiz-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	death_checker(t_table *table)
{
	int	i;
	int	time_death;

	while (table->alive)
	{
		i = 0;
		while (i < table->total_philos)
		{
			time_death = get_time_ms(table->init_time)
				- table->philo[i].last_meal;
			if (time_death >= table->time_die)
			{
				ft_print(table->philo, DEAD);
				table->alive = 0;
				break ;
			}
			i++;
		}
		if (table->all_full == 1 || table->alive == 0)
			break ;
		usleep(100);
	}
}
