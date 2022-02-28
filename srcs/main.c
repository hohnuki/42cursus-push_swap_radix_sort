#include "../includes/push_swap.h"

void	compression_array(t_info *info)
{
	int array[info->argc];
	int i;
	int j;
	int tmp;

	i = 0;
	while (i < info->argc)
	{
		array[i] = info->stack.a[i];
		i++;
	}
	i = 0;
	tmp = 0;
	while (i < info->argc)
	{
		j = i;
		while (j < info->argc)
		{
			if (array[i] > array[j])
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
			j++;
		}
		i++;
	}
	i = 0;
	while (i < info->argc)
	{
		j = 0;
		while (j < info->argc)
		{
			if (array[i] == info->stack.a[j])
				info->stack.compression_a[j] = i;
			j++;
		}
		i++;
	}
//	stack_debug(info);
}

void	stack_argv(t_info *info)
{
	info->stack.a = ft_calloc(info->argc, sizeof(int));
	info->stack.compression_a = ft_calloc(info->argc, sizeof(int));
	info->stack.b = ft_calloc(info->argc, sizeof(int));
	info->stack.compression_b = ft_calloc(info->argc, sizeof(int));
	int	i = 0;
	while (i < info->argc)
	{
		info->stack.a[i] = ft_atoi(info->argv[i + 1]);
		i++;
	}
	compression_array(info);
}

int	main(int argc, char **argv)
{
	t_info	info;

	info.argc = argc - 1;
	info.argv = argv;
	stack_argv(&info);
	if (info.argc >= 7)
		sort_case_over7(&info);
}

