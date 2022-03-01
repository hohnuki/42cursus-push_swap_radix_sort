#include "../includes/push_swap.h"

void	sort_case_3(t_info *info)
{
	if (info->stack.a[0] > info->stack.a[1] && info->stack.a[1] < info->stack.a[2] && info->stack.a[0] < info->stack.a[2])
		ra(info);
	else if (info->stack.a[0] < info->stack.a[1] && info->stack.a[1] < info->stack.a[2] && info->stack.a[0] < info->stack.a[2])
	{
		sa(info);
		rra(info);
	}
	else if (info->stack.a[0] > info->stack.a[1] && info->stack.a[1] < info->stack.a[2] && info->stack.a[0] > info->stack.a[2])
		sa(info);
	else if (info->stack.a[0] < info->stack.a[1] && info->stack.a[1] > info->stack.a[2] && info->stack.a[0] > info->stack.a[2])
	{
		sa(info);
		ra(info);
	}
	else if (info->stack.a[0] < info->stack.a[1] && info->stack.a[1] > info->stack.a[2] && info->stack.a[0] < info->stack.a[2])
		rra(info);
}

void	sort_case_3_b(t_info *info)
{
	if (info->stack.b[0] > info->stack.b[1] && info->stack.b[1] < info->stack.b[2] && info->stack.b[0] < info->stack.b[2])
		rb(info);
	else if (info->stack.b[0] < info->stack.b[1] && info->stack.b[1] < info->stack.b[2] && info->stack.b[0] < info->stack.b[2])
	{
		sb(info);
		rrb(info);
	}
	else if (info->stack.b[0] > info->stack.b[1] && info->stack.b[1] < info->stack.b[2] && info->stack.b[0] > info->stack.b[2])
		sb(info);
	else if (info->stack.b[0] < info->stack.b[1] && info->stack.b[1] > info->stack.b[2] && info->stack.b[0] > info->stack.b[2])
	{
		sb(info);
		rb(info);
	}
	else if (info->stack.b[0] < info->stack.b[1] && info->stack.b[1] > info->stack.b[2] && info->stack.b[0] < info->stack.b[2])
		rrb(info);
}