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
	while (i < info->argc)
	{
		j = info->argc - 1;
		while (j >= 0)
		{
			if (((info->stack.compression_a[info->stack.head_a] >> k) & 1) == 0)
			{
				pb(info);
				pb_count++;
			}
			else
				ra(info);
			j--;
		}
		while (pb_count > 0)
		{
			pa(info);
			pb_count--;
		}
		i *= 2;
		k++;
	}
}