#include "../includes/philo.h"

int is_number(char **argv)
{
    int i;
    int j;

    i = 0;
    while (argv[j])
    {
        j = 0;
        while (argv[j][i])
        {
            if (argv[j][i] < '0' || argv[j][i] > '9')
                return (0);
            i++;
        }
        j++;
    }
    return (1);
}

int parse_args(int argc, char **argv, t_args *data)
{
    if (argc == 5 && is_number(argv))
    {
        data->total_philos = ft_atoi(argv[1]);
        data->time_die = ft_atoi(argv[2]);
        data->time_eat = ft_atoi(argv[3]);
        data->time_sleep = ft_atoi(argv[3]);
        return (0);
    }
    return (1);
}