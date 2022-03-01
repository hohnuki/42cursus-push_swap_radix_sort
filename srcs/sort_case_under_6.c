#include "../includes/push_swap.h"

void	sort_case_under_6(t_info *info)
{
	int	i;

	i = 0;
	stack_debug(info);
	while (i < info->argc)
	{
		if (info->stack.compression_a[info->stack.head_a] == 0 || info->stack.compression_a[info->stack.head_a] == 1 || info->stack.compression_a[info->stack.head_a] == 2)
			pb(info);
		else
			ra(info);
		i++;
	}
	sort_case_3(info);
	sort_case_3_b(info);
	stack_debug(info);
	pa(info);
	pa(info);
	pa(info);
}