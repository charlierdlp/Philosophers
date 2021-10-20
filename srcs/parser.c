#include "../includes/philo.h"

int is_number(char **argv)
{
    int i;
    int j;

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
    return (1);
}

int parse_args(int argc, char **argv, t_args *args)
{
    if (argc == 2 && is_number(argv))
    {
        args->total_philos = ft_atoi(argv[1]);
        //args->time_die = ft_atoi(argv[2]);
        //args->time_eat = ft_atoi(argv[3]);
        //args->time_sleep = ft_atoi(argv[3]);
        return (1);
    }
    else
        write(1, "Error\n", 6);
    return (0);
}