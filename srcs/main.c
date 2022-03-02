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

void	string_to_array(t_info *info)
{
	char	**str;
	int 	i;

	info->stack.a = ft_calloc(ft_strlen(info->argv[1]), sizeof(int));
	if (info->stack.a == NULL)
		error_message(info);
	info->stack.compression_a = ft_calloc(ft_strlen(info->argv[1]), sizeof(int));
	if (info->stack.compression_a == NULL)
		error_message(info);
	info->stack.b = ft_calloc(ft_strlen(info->argv[1]), sizeof(int));
	if (info->stack.b == NULL)
		error_message(info);
	info->stack.compression_b = ft_calloc(ft_strlen(info->argv[1]), sizeof(int));
	if (info->stack.compression_b == NULL)
		error_message(info);

	str = ft_split(info->argv[1], ' ');
	i = 0;
	while (str[i] != NULL)
	{
		info->stack.a[i] = ps_atoi(str[i], info);
		i++;
	}
}


void	stack_argv(t_info *info)
{
	if (ft_strchr(info->argv[1], ' ') != NULL)
		string_to_array(info);
	else
	{
		info->stack.a = ft_calloc(info->argc, sizeof(int));
		if (info->stack.a == NULL)
			error_message(info);
		info->stack.compression_a = ft_calloc(info->argc, sizeof(int));
		if (info->stack.compression_a == NULL)
			error_message(info);
		info->stack.b = ft_calloc(info->argc, sizeof(int));
		if (info->stack.b == NULL)
			error_message(info);
		info->stack.compression_b = ft_calloc(info->argc, sizeof(int));
		if (info->stack.compression_b == NULL)
			error_message(info);

		int i = 0;
		int	j = info->argc;
		while (i < info->argc)
		{
			info->stack.a[i] = ps_atoi(info->argv[j], info);
			i++;
			j--;
		}
	}
//	stack_debug(info);
	compression_array(info);
}

int	main(int argc, char **argv)
{
	t_info	info;

	if (argc == 1)
		exit(EXIT_FAILURE);
	info.argc = argc - 1;
	info.argv = argv;
	info.stack.head_a = info.argc - 1;
	info.stack.head_b = -1;
	stack_argv(&info);
	check_duplicate(&info);
	if (info.argc == 2)
		sort_case_2(&info);
	else if (info.argc == 3)
		sort_case_3(&info);
	else if (info.argc <= 6)
		sort_case_under_6(&info);
	else if(info.argc >= 7)
		sort_case_over7(&info);
//	stack_debug(&info);
	free_element(&info);
}

