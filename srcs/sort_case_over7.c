#include "../includes/push_swap.h"

void	sort_case_over7(t_info *info)
{
	int i;
	int j;
	int k;
	int pb_count;

	i = 1;
	k = 0;
	pb_count = 0;
	while (i < 100)
	{
		j = info->argc;
		while (j > 0)
		{
			if (((info->stack.compression_a[j] >> k) & i) == 1)
			{
				pb(info);
				pb_count++;
			}
			else
				ra(info);
			j--;
		}
		stack_debug(info);
		while (pb_count > 0)
		{
			pa(info);
			pb_count--;
		}
		stack_debug(info);
		i *= 2;
		k++;
	}
	stack_debug(info);
}