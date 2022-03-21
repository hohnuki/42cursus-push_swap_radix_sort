#include "../includes/push_swap.h"

void	memory_allocate(t_info *info, size_t size)
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

static void	argv_to_array(t_info *info)
{
	size_t	i;
	size_t	j;

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
		character_literal_to_array(info);
	else
		argv_to_array(info);
	compression_array(info);
}
