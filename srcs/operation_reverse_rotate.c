#include "../includes/push_swap.h"

void	rra(t_info *info)
{
	int	tmp_a;
	int	tmp_compression_a;
	int	i;

	printf("rra\n");
	i = 0;
//	printf("\x1b[36m[i = %d]\n\033[m", i);
	tmp_a = info->stack.a[0];
//	printf("\x1b[36m[tmp_a = %d]\n\033[m", tmp_a);
	while (i < info->stack.head_a)
	{
		info->stack.a[i] = info->stack.a[i + 1];
		i++;
	}
	info->stack.a[info->stack.head_a] = tmp_a;

	i = 0;
	tmp_compression_a = info->stack.compression_a[0];
	while (i < info->stack.head_a)
	{
		info->stack.compression_a[i] = info->stack.compression_a[i + 1];
		i++;
	}
	info->stack.compression_a[info->stack.head_a] = tmp_compression_a;
}

void	rrb(t_info *info)
{
	int	tmp_b;
	int	tmp_compression_b;
	int	i;

	printf("rrb\n");
	i = 0;
//	printf("\x1b[36m[i = %d]\n\033[m", i);
	tmp_b = info->stack.b[0];
//	printf("\x1b[36m[tmp_b = %d]\n\033[m", tmp_b);
	while (i < info->stack.head_b)
	{
		info->stack.b[i] = info->stack.b[i + 1];
		i++;
	}
	info->stack.b[info->stack.head_b] = tmp_b;

	i = 0;
	tmp_compression_b = info->stack.compression_b[0];
	while (i < info->stack.head_b)
	{
		info->stack.compression_b[i] = info->stack.compression_b[i + 1];
		i++;
	}
	info->stack.compression_b[info->stack.head_b] = tmp_compression_b;
}