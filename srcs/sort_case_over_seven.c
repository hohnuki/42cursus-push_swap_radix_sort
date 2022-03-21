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

static void	execute_pb(t_info *info)
{
	pb(info);
	info->stack.pb_count++;
}

void	sort_case_over_seven(t_info *info)
{
	size_t	binary_digit;
	size_t	argc_i;
	size_t	shift_num;

	binary_digit = 1;
	shift_num = 0;
	while (binary_digit < info->argc)
	{
		argc_i = info->argc - 1;
		while (argc_i >= 0)
		{
			if (((info->stack.compression_a[info->stack.head_a] >> \
			shift_num) & 1) == 0)
				execute_pb(info);
			else
				ra(info);
			if (argc_i == 0)
				break ;
			argc_i--;
		}
		execute_pa(info);
		binary_digit *= 2;
		shift_num++;
	}
}
