/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cruiz-de <cruiz-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 19:05:45 by cruiz-de          #+#    #+#             */
/*   Updated: 2021/11/25 19:06:20 by cruiz-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	is_number(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	if (ft_atoi(argv[1]) == 0)
		return (0);
	else if (ft_atoi(argv[1]) > 200)
		return (0);
	else
		return (1);
}

int	parse_args(int argc, char **argv, t_table *table)
{
	if ((argc == 5 || argc == 6) && is_number(argv))
	{
		table->total_philos = ft_atoi(argv[1]);
		table->time_die = ft_atoi(argv[2]);
		table->time_eat = ft_atoi(argv[3]);
		table->time_sleep = ft_atoi(argv[4]);
		table->max_meals = -1;
		table->all_full = 0;
		if (argc == 6)
			table->max_meals = ft_atoi(argv[5]);
		return (1);
	}
	else
		write(1, "Error\n", 6);
	return (0);
}
