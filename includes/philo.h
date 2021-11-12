#ifndef PHILO_H
# define PHILO_H

#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h> 
#include <sys/time.h>

typedef struct s_table
{
    int     total_philos;
    int     time_die;
    int     time_eat;
    int     time_sleep;
    pthread_mutex_t write;
}               t_table;

typedef struct s_philo
{
    t_table     *table;
    int         id;
    pthread_t   thread;
    pthread_mutex_t fork;
}               t_philo;

typedef struct s_global
{
    t_table	table;
    t_philo	*philo;
}               t_global;

int parse_args(int argc, char **argv, t_global *global);
int	ft_atoi(const char *str);

#endif