/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cruiz-de <cruiz-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 18:05:04 by cruiz-de          #+#    #+#             */
/*   Updated: 2021/11/26 19:06:21 by cruiz-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

uint64_t	get_time_ms(uint64_t measure)
{
	struct timeval time;
	unsigned long time_ms;
	unsigned long seconds_to_ms;

	gettimeofday(&time, NULL);

	seconds_to_ms = time.tv_sec * 1000;
	time_ms = seconds_to_ms + time.tv_usec / 1000;
	return (time_ms - measure);
}

void	ft_usleep(uint64_t time_in_ms)
{
	uint64_t			start_time;

	start_time = get_time_ms(0);
	while ((get_time_ms(0) - start_time) < time_in_ms)
		usleep(100);
}

int	ft_atoi(const char *str)
{
	int		neg;
	int		n;
	int		i;

	i = 0;
	n = 0;
	neg = 1;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-')
		neg = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + (str[i] - '0');
		i++;
	}
	return (n * neg);
}
