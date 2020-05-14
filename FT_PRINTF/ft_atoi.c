#include "ft_printf.h"

int		ft_atoi(char **arg)
{
	int		nbr;
	int		sign;
	char	*str;

	str = *arg;
	sign = 1;
	nbr = 0;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		nbr = nbr * 10 + (*str - '0');
		str++;
	}
	*arg = str;
	return (sign * nbr);
}
