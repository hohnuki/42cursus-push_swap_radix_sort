#include "../includes/push_swap.h"

void	is_sorted(t_info *info)
{
	int i;

	i = info->stack.head_a;
	while (i > 0)
	{
		if (info->stack.a[i] > info->stack.a[i - 1])
			return ;
		i--;
	}
	free_element(info);
	exit(EXIT_SUCCESS);
}