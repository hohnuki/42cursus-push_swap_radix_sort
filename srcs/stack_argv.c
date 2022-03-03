#include "../includes/push_swap.h"

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

	info->argc = str_separate_count(info->argv[1], ' ');
	str = ft_split(info->argv[1], ' ');
	i = 0;
	while (str[i] != NULL)
	{
		info->stack.a[i] = ps_atoi(str[i], info);
		i++;
	}
}

void	argv_to_array(t_info *info)
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

void	stack_argv(t_info *info)
{
	if (ft_strchr(info->argv[1], ' ') != NULL)
		string_to_array(info);
	else
		argv_to_array(info);
	compression_array(info);
}