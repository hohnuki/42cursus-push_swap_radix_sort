#include "../includes/push_swap.h"

static void	measure_string_size(t_info *info)
{
	size_t	i;

	i = 1;
	info->argc = 1;
	while (info->argv[i] != NULL)
	{
		info->argc += str_separate_count(info->argv[i], ' ');
		i++;
	}
}

static void	separate_argv_to_stack(t_info *info)
{
	char	**str;
	size_t	argc_i;
	size_t	sep_num;
	size_t	sa_i;

	argc_i = info->argc_duplicate;
	sa_i = 0;
	while (argc_i > 0)
	{
		sep_num = str_separate_count(info->argv[argc_i], ' ');
		str = ft_split(info->argv[argc_i], ' ');
		while (sep_num > 0)
		{
			info->stack.a[sa_i] = ps_atoi(str[sep_num - 1], info);
			sep_num--;
			sa_i++;
		}
		free_split_str(str);
		argc_i--;
	}
}

void	one_argument_to_array(t_info *info)
{
	measure_string_size(info);
	info->argc -= 1;
	info->stack.head_a = info->argc - 1;
	stack_memory_allocate(info, info->argc);
	separate_argv_to_stack(info);
}
