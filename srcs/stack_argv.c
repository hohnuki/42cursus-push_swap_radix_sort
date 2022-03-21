#include "../includes/push_swap.h"

void	*xmalloc(t_info *info, size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr == NULL)
		error_message(info);
	return (ptr);
}

void	stack_memory_allocate(t_info *info, size_t size)
{
	info->stack.a = xmalloc(info, size * sizeof(int));
	info->stack.compression_a = xmalloc(info, size * sizeof(int));
	info->stack.b = xmalloc(info, size * sizeof(int));
	info->stack.compression_b = xmalloc(info, size * sizeof(int));
}

static void	one_number_per_argument_to_array(t_info *info)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = info->argc;
	stack_memory_allocate(info, info->argc);
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
		one_argument_to_array(info);
	else
		one_number_per_argument_to_array(info);
	compression_array(info);
}
