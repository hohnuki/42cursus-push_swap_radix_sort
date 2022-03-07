#include "../includes/push_swap.h"

void	pa(t_info *info)
{
	ft_putendl_fd("pa", 1);
	info->stack.head_a++;
	info->stack.a[info->stack.head_a] = info->stack.b[info->stack.head_b];
	info->stack.b[info->stack.head_b] = '\0';
	info->stack.compression_a[info->stack.head_a] = \
	info->stack.compression_b[info->stack.head_b];
	info->stack.compression_b[info->stack.head_b] = '\0';
	info->stack.head_b--;
}

void	pb(t_info *info)
{
	ft_putendl_fd("pb", 1);
	info->stack.head_b++;
	info->stack.b[info->stack.head_b] = info->stack.a[info->stack.head_a];
	info->stack.a[info->stack.head_a] = '\0';
	info->stack.compression_b[info->stack.head_b] = \
	info->stack.compression_a[info->stack.head_a];
	info->stack.compression_a[info->stack.head_a] = '\0';
	info->stack.head_a--;
}
