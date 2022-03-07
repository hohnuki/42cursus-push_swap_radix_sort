#include "../includes/push_swap.h"

static void	measure_string_size(t_info *info)
{
	int	i;

	i = 1;
	info->argc = 1;
	while (info->argv[i] != NULL)
	{
		info->argc += str_separate_count(info->argv[i], ' ');
		i++;
	}
}

static void	separate_argv_to_(t_info *info)
{
	char	**str;
	int		i;
	int		j;
	int		k;

	i = info->argc_hoge;
	k = 0;
	while (i > 0)
	{
		j = str_separate_count(info->argv[i], ' ');
		str = ft_split(info->argv[i], ' ');
		while (j - 1 > 0 || j == 1)
		{
			info->stack.a[k] = ps_atoi(str[j - 1], info);
			j--;
			k++;
		}
		free_split_str(str);
		i--;
	}
}

void	string_to_array(t_info *info)
{
	measure_string_size(info);
	info->argc -= 1;
	info->stack.head_a = info->argc - 1;
	memory_allocate(info, info->argc);
	separate_argv_to_(info);
}
