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
    uint64_t    init_time;

    int     total_philos;
    int     time_die;
    int     time_eat;
    int     time_sleep;
    int     alive;

    t_philo	    *philo;

    pthread_mutex_t write;

}               t_table;

typedef struct s_philo
{
    t_table     *table;

    int         id;
    int     last_meal;

    pthread_t   thread;
    pthread_mutex_t fork;

}               t_philo;

typedef enum state {
	EATING,
	SLEEPING,
	THINKING,
    FORKING,
    DEAD
} t_state;

void *start(void *data);
int ft_print(t_philo *philo, t_state);
void death_checker(t_table *table);
int init_philos(t_table *table);
int init_mutex(t_table *table);
int create_threads(t_table *table);
int parse_args(int argc, char **argv, t_table *table);
int	ft_atoi(const char *str);
uint64_t	get_time_ms(uint64_t measure);
void	ft_usleep(uint64_t time_in_ms);
#endif