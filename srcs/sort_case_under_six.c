#include "../includes/push_swap.h"

void	sort_case_under_six(t_info *info)
{
	size_t	i;

	i = 0;
	while (i < info->argc)
	{
		if (info->stack.compression_a[info->stack.head_a] == 0 \
		|| info->stack.compression_a[info->stack.head_a] == 1 \
		|| info->stack.compression_a[info->stack.head_a] == 2)
			pb(info);
		else
			ra(info);
		i++;
	}
	if (info->stack.head_a + 1 == 3)
		sort_case_three(info);
	else if (info->stack.head_a + 1 == 2)
		sort_case_two(info);
	sort_case_three_b(info);
	pa(info);
	pa(info);
	pa(info);
}
