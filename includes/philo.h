#ifndef PHILO_H
# define PHILO_H

#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h> 
#include <sys/time.h>

typedef struct s_philo	t_philo;

typedef struct s_table
{
    uint64_t    current_time;
    int     total_philos;
    int     time_die;
    int     time_eat;
    int     time_sleep;
    t_philo	    *philo;
    pthread_mutex_t write;
}               t_table;

typedef struct s_philo
{
    t_table     *table;
    int         id;
    pthread_t   thread;
    pthread_mutex_t fork;
}               t_philo;


int parse_args(int argc, char **argv, t_table *table);
int	ft_atoi(const char *str);
uint64_t	get_time_ms(uint64_t reference);

#endif