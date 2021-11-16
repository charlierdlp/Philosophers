#include "../includes/philo.h"

uint64_t	get_time_ms(uint64_t reference)
{
	struct	timeval ti;

	if (gettimeofday(&ti, NULL) == -1)
		return (-1);
	return(ti.tv_sec * 1000 + ti.tv_usec / 1000 - reference);
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
