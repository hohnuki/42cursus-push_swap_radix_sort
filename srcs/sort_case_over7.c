#include "../includes/push_swap.h"

static void	execute_pa(t_info *info)
{
	while (info->stack.pb_count > 0)
	{
		pa(info);
		info->stack.pb_count--;
	}
	is_sorted(info);
}

void	sort_case_over7(t_info *info)
{
	int	i;
	int	j;
	int	k;

	i = 1;
	k = 0;
	while (i < info->argc)
	{
		j = info->argc - 1;
		while (j >= 0)
		{
			if (((info->stack.compression_a[info->stack.head_a] >> k) & 1) == 0)
			{
				pb(info);
				info->stack.pb_count++;
			}
			else
				ra(info);
			j--;
		}
		execute_pa(info);
		i *= 2;
		k++;
	}
}
