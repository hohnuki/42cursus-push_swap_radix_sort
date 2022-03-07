#include "../includes/push_swap.h"

static void	memory_allocate(t_info *info, size_t size)
{
	info->stack.a = ft_calloc(size, sizeof(int));
	if (info->stack.a == NULL)
		error_message(info);
	info->stack.compression_a = ft_calloc(size, sizeof(int));
	if (info->stack.compression_a == NULL)
		error_message(info);
	info->stack.b = ft_calloc(size, sizeof(int));
	if (info->stack.b == NULL)
		error_message(info);
	info->stack.compression_b = ft_calloc(size, sizeof(int));
	if (info->stack.compression_b == NULL)
		error_message(info);
}

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

static void	string_to_array(t_info *info)
{
	measure_string_size(info);
	info->argc -= 1;
	info->stack.head_a = info->argc - 1;
	memory_allocate(info, info->argc);
	separate_argv_to_(info);
}

static void	argv_to_array(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	j = info->argc;
	memory_allocate(info, info->argc);
	while (i < info->argc)
	{
		info->stack.a[i] = ps_atoi(info->argv[j], info);
		i++;
		j--;
	}
}

void	stack_argv(t_info *info)
{
	if (ft_strchr(info->argv[1], ' ') != NULL)
		string_to_array(info);
	else
		argv_to_array(info);
	compression_array(info);
}
