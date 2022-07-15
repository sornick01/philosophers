#include "../includes/philo.h"

static int	is_space(int c)
{
	if (c == '\t' || c == ' ' || c == '\r'
		|| c == '\n' || c == '\f' || c == '\v')
		return (1);
	return (0);
}

static int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	long long		res;
	int				sign;

	res = 0;
	sign = 1;
	while (is_space(*str))
		str++;
	if (*str == '-')
	{
		sign *= -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (ft_isdigit(*str))
	{
		res = res * 10 + (*str++ - '0');
		if (res < 0)
		{
			if (sign == -1)
				return (0);
			return (-1);
		}
	}
	return ((int)(res * sign));
}

int	ft_isnumber(const char *str)
{
	if (!str)
		return (0);
	if (*str == '-')
	{
		++str;
		if (!(*str) || (*str && !ft_isdigit(*str)))
			return (0);
	}
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		++str;
	}
	return (1);
}