#include "../includes/push_swap.h"

static void	init_structure(t_info *info)
{
	info->argc = 0;
	info->argv = NULL;
	info->stack.a = NULL;
	info->stack.compression_a = NULL;
	info->stack.b = NULL;
	info->stack.compression_b = NULL;
	info->stack.head_a = 0;
	info->stack.head_b = 0;
	info->stack.pb_count = 0;
}

static void	set_initial_date(t_info *info, int argc, char **argv)
{
	info->argc = argc - 1;
	info->argv = argv;
	info->stack.head_a = info->argc - 1;
	info->stack.head_b = -1;
}

int	main(int argc, char **argv)
{
	t_info	info;

	if (argc == 1)
		exit(EXIT_FAILURE);
	init_structure(&info);
	set_initial_date(&info, argc, argv);
	stack_argv(&info);
	check_duplicate(&info);
	is_sorted(&info);
	if (info.argc == 2)
		sort_case_two(&info);
	else if (info.argc == 3)
		sort_case_three(&info);
	else if (info.argc <= 6)
		sort_case_under_six(&info);
	else if (info.argc >= 7)
		sort_case_over_seven(&info);
	free_element(&info);
	return (0);
}
