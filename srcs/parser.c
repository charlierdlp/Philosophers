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

int parse_args(int argc, char **argv, t_global *global)
{
    if (argc == 5 && is_number(argv))
    {
        global->table.total_philos = ft_atoi(argv[1]);
        global->table.time_die = ft_atoi(argv[2]);
        global->table.time_eat = ft_atoi(argv[3]);
        global->table.time_sleep = ft_atoi(argv[3]);
        return (1);
    }
    else
        write(1, "Error\n", 6);
    return (0);
}