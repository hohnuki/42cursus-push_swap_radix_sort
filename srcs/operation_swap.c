#include "../includes/push_swap.h"

void	sa(t_info *info)
{
	int	tmp;

	tmp = 0;
	ft_putendl_fd("sa", 1);
	tmp = info->stack.a[info->stack.head_a];
	info->stack.a[info->stack.head_a] = info->stack.a[info->stack.head_a - 1];
	info->stack.a[info->stack.head_a - 1] = tmp;
	tmp = 0;
	tmp = info->stack.compression_a[info->stack.head_a];
	info->stack.compression_a[info->stack.head_a] = \
	info->stack.compression_a[info->stack.head_a - 1];
	info->stack.compression_a[info->stack.head_a - 1] = tmp;
}

void	sb(t_info *info)
{
	int	tmp;

	tmp = 0;
	ft_putendl_fd("sb", 1);
	tmp = info->stack.b[info->stack.head_b];
	info->stack.b[info->stack.head_b] = info->stack.b[info->stack.head_b - 1];
	info->stack.b[info->stack.head_b - 1] = tmp;
	tmp = 0;
	tmp = info->stack.compression_b[info->stack.head_b];
	info->stack.compression_b[info->stack.head_b] = \
	info->stack.compression_b[info->stack.head_b - 1];
	info->stack.compression_b[info->stack.head_b - 1] = tmp;
}
