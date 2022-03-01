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
	while (i < 600)
	{
		j = info->argc - 1;
		while (j > 0)
		{
//			printf("\x1b[36m[j = %d, compression[info->stack.head_a] = %d, a[info->stack.head_a] = %d, k = %d, info->stack.head_a = %d]\n\033[m", j, info->stack.compression_a[info->stack.head_a], info->stack.a[info->stack.head_a], k, info->stack.head_a);
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
	stack_debug(info);
}