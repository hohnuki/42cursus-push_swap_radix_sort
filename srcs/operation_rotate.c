#include "../includes/push_swap.h"

void	ra(t_info *info)
{
	int		tmp_a;
	int		tmp_compression_a;
	size_t	i;

	ft_putendl_fd("ra", 1);
	i = info->stack.head_a;
	tmp_a = info->stack.a[i];
	while (i > 0)
	{
		info->stack.a[i] = info->stack.a[i - 1];
		i--;
	}
	info->stack.a[0] = tmp_a;
	i = info->stack.head_a;
	tmp_compression_a = info->stack.compression_a[i];
	while (i > 0)
	{
		info->stack.compression_a[i] = info->stack.compression_a[i - 1];
		i--;
	}
	info->stack.compression_a[0] = tmp_compression_a;
}

void	rb(t_info *info)
{
	int		tmp_b;
	int		tmp_compression_b;
	size_t	i;

	ft_putendl_fd("rb", 1);
	i = info->stack.head_b;
	tmp_b = info->stack.b[i];
	while (i > 0)
	{
		info->stack.b[i] = info->stack.b[i - 1];
		i--;
	}
	info->stack.b[0] = tmp_b;
	i = info->stack.head_b;
	tmp_compression_b = info->stack.compression_b[i];
	while (i > 0)
	{
		info->stack.compression_b[i] = info->stack.compression_b[i - 1];
		i--;
	}
	info->stack.compression_b[0] = tmp_compression_b;
}
