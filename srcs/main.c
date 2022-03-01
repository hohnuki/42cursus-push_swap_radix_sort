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
}

void	stack_argv(t_info *info)
{
	info->stack.a = ft_calloc(info->argc, sizeof(int));
	if (info->stack.a == NULL)
		error_message(info, "info->stack.a is not allocated.");
	info->stack.compression_a = ft_calloc(info->argc, sizeof(int));
	if (info->stack.compression_a == NULL)
		error_message(info, "info->stack.compression_a is not allocated.");
	info->stack.b = ft_calloc(info->argc, sizeof(int));
	if (info->stack.b == NULL)
		error_message(info, "info->stack.b is not allocated.");
	info->stack.compression_b = ft_calloc(info->argc, sizeof(int));
	if (info->stack.compression_b == NULL)
		error_message(info, "info->stack.compression_b is not allocated.");
	int i = 0;
	int	j = info->argc;
	while (i < info->argc)
	{
		info->stack.a[i] = ft_atoi(info->argv[j]);
		i++;
		j--;
	}
	compression_array(info);
	stack_debug(info);
}

int	main(int argc, char **argv)
{
	t_info	info;

	info.argc = argc - 1;
	info.argv = argv;
	info.stack.head_a = info.argc - 1;
	info.stack.head_b = -1;
	stack_argv(&info);
	if (info.argc == 2)
		sort_case_2(&info);
	else if (info.argc == 3)
		sort_case_3(&info);
	else if (info.argc <= 6)
		sort_case_under_6(&info);
	else if(info.argc >= 7)
		sort_case_over7(&info);
	stack_debug(&info);
	free_element(&info);
}

