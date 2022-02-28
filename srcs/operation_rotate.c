#include "../includes/push_swap.h"

void	ra(t_info *info)
{
	int	tmp_a;
	int	tmp_compression_a;
	int	i;

	printf("ra \n");
	i = info->stack.head_a - 1;
	tmp_a = info->stack.a[i];
	while (i > 0)
	{
		info->stack.a[i] = info->stack.a[i - 1];
		i--;
	}
	info->stack.a[0] = tmp_a;
	i = info->stack.head_a - 1;
	tmp_compression_a = info->stack.compression_a[i];
	while (i > 0)
	{
		info->stack.compression_a[i] = info->stack.compression_a[i - 1];
		i--;
	}
	info->stack.compression_a[0] = tmp_compression_a;
}