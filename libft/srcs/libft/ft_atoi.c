#include "libft.h"

int	ft_atoi(const char *str)
{
	long long	flag;
	long long	res;

	flag = 1;
	res = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-')
	{
		flag *= -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		res = 10 * res + *str - '0';
		str++;
		if (res - 1 > INT_MAX || res < INT_MIN)
			return (res);
	}
	if (res != 0)
		return (flag * res);
	return (0);
}
