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
	info->stack.a = xmalloc(info, sizeof(int) * size);
	info->stack.compression_a = xmalloc(info, sizeof(int) * size);
	info->stack.b = xmalloc(info, sizeof(int) * size);
	info->stack.compression_b = xmalloc(info, sizeof(int) * size);
}

static void	one_number_per_argument_to_array(t_info *info)
{
	size_t	a_i;
	size_t	argv_i;

	a_i = 0;
	argv_i = info->argc;
	stack_memory_allocate(info, info->argc);
	while (a_i < info->argc)
	{
		if (ft_strlen(info->argv[argv_i]) > 12)
			error_message_and_exit(info);
		info->stack.a[a_i] = ps_atoi(info->argv[argv_i], info);
		a_i++;
		argv_i--;
	}
}

void	stack_argv(t_info *info)
{
	one_number_per_argument_to_array(info);
	compression_array(info);
}
