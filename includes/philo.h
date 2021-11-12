#ifndef PHILO_H
# define PHILO_H

#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h> 
#include <sys/time.h>

typedef struct s_args
{
    int     total_philos;
    int     time_die;
    int     time_eat;
    int     time_sleep;
}               t_args;

typedef struct s_data
{
    t_args      *philo;
    pthread_t   thread;
    pthread_mutex_t *forks;
}               t_data;

int parse_args(int argc, char **argv, t_args *args);
int	ft_atoi(const char *str);

#endif