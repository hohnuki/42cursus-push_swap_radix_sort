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