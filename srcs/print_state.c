/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cruiz-de <cruiz-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 19:30:34 by cruiz-de          #+#    #+#             */
/*   Updated: 2021/11/23 20:05:36 by cruiz-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int ft_print(t_philo *philo, t_state state)
{
    pthread_mutex_lock(&philo->table->write);
    if (state == EATING)
        printf("%llu %d is eating\n", get_time_ms(philo->table->init_time), philo->id);
    else if (state == SLEEPING)
        printf("%llu %d is sleeping\n", get_time_ms(philo->table->init_time), philo->id);
    else if (state == THINKING)
        printf("%llu %d is thinking\n", get_time_ms(philo->table->init_time), philo->id);
    else if (state == FORKING)
        printf("%llu %d has taken a fork\n", get_time_ms(philo->table->init_time), philo->id);
    else if (state == DEAD)
        printf("%llu %d has died\n", get_time_ms(philo->table->init_time), philo->table->philo->id);
    pthread_mutex_unlock(&philo->table->write);
    return (0);
}
