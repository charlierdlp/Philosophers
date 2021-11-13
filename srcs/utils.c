#include "../includes/philo.h"

unsigned long	get_time_ms(void)
{
	struct timeval time;
	unsigned long time_ms;
	unsigned long seconds_to_ms;

	gettimeofday(&time, NULL);

	seconds_to_ms = time.tv_sec * 1000;
	time_ms = seconds_to_ms + time.tv_usec / 1000;
	return (time_ms);
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
