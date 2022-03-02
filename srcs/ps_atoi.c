#include "../includes/push_swap.h"

static int	check_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

static int	check_negative(int n_i, int ope_i)
{
	int	i;

	i = 0;
	if (ope_i > 1 || n_i > 1)
		i = 0;
	else if (n_i % 2 == 1)
		i = -1;
	else
		i = 1;
	return (i);
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
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			n_i++;
		ope_i++;
		i++;
	}
	while (ft_isdigit(str[i]))
		ans = (ans * 10) + ((str[i++] - '0'));
	if (ans >= INT_MAX || ans <= INT_MIN)
		error_message(info, "invalid argv\n");
	return (ans * check_negative(n_i, ope_i));
}
