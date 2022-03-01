#include "../includes/push_swap.h"

void	sa(t_info *info)
{
	int	tmp;

	tmp = 0;
	printf("sa\n");
	tmp = info->stack.a[info->stack.head_a];
	info->stack.a[info->stack.head_a] = info->stack.a[info->stack.head_a - 1];
	info->stack.a[info->stack.head_a] = tmp;

	tmp = 0;
	tmp = info->stack.compression_a[info->stack.head_a];
	info->stack.compression_a[info->stack.head_a] = info->stack.compression_a[info->stack.head_a - 1];
	info->stack.compression_a[info->stack.head_a] = tmp;
}

