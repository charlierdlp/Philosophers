#ifndef PHILO_H
# define PHILO_H

#include <unistd.h>
#include <pthread.h> 

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
}               t_data;
#endif