
#include "push_swap.h"

long	ft_long_atoi(const char *nptr)
{
	size_t	i;
	int		m;
	long	res;

	m = 1;
	res = 0;
	i = 0;
	while ((nptr[i] == ' ') || (nptr[i] >= '\t' && nptr[i] <= '\r'))
		i++;
	if (nptr[i] == '-')
	{
		i++;
		m = -1;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = (res * 10) + (nptr[i] - '0');
		i++;
	}
	return (res * m);
}

int	check_nint(char *str)
{
	long	imax;
	long	imin;

	imax = 2147483647;
	imin = -2147483648;
	if (ft_long_atoi(str) > imax || ft_long_atoi(str) < imin)
		return (0);
	return (1);
}

void	error_msg(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(0);
}

int	check_arg(int argc, char **argv)
{
	int	i;
	int	j;
	int	k;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		k = 1;
		if (!check_nint(argv[i]))
			error_msg();
		while (argv[i][k])
		{
			if (argv[i][0] != '-' && (argv[i][0] < '0' || argv[i][0] > '9'))
				error_msg();
			if (argv[i][k] < '0' || argv[i][k] > '9')
				error_msg();
			k++;
		}
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				error_msg();
			j++;
		}
		i++;
	}
	return (1);
}
