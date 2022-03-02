#include "../includes/push_swap.h"

static int	check_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '+'
		|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

static int	check_negative(int n_i, int ope_i, t_info *info)
{
	int	i;

	i = 0;
	if (ope_i > 1 || n_i > 1)
	{
		error_message(info);
		exit(EXIT_FAILURE);
	}
	else if (n_i % 2 == 1)
		i = -1;
	else
		i = 1;
	return (i);
}

static void	check_range_int(long long ans, t_info *info)
{
	if (ans > INT_MAX || ans < INT_MIN)
	{
		error_message(info);
		exit(EXIT_FAILURE);
	}
}

int	ps_atoi(const char *str, t_info *info)
{
	size_t		i;
	int			n_i;
	int			ope_i;
	long long	ans;

	i = 0;
	n_i = 0;
	ope_i = 0;
	ans = 0;
	while (check_isspace(str[i]) == 1)
	{
		error_message(info);
		exit(EXIT_FAILURE);
	}
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			n_i++;
		ope_i++;
		i++;
		if (str[i] == '\0')
		{
			error_message(info);
			exit(EXIT_FAILURE);
		}
	}
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0)
		{
			error_message(info);
			exit(EXIT_FAILURE);
		}
		ans = (ans * 10) + ((str[i++] - '0'));
	}
	ans *= check_negative(n_i, ope_i, info);
	check_range_int(ans, info);
	return (ans);
}
