#include "../includes/push_swap.h"

static void	init_structure(t_info *info)//TODO:info->stackの初期化の有無
{
	info->argc = 0;
	info->argv = NULL;
	info->argc_hoge = 0;
	info->stack.a = NULL;
	info->stack.compression_a = NULL;
	info->stack.b = NULL;
	info->stack.compression_b = NULL;
	info->stack.head_a = 0;
	info->stack.head_b = 0;
}

static void	set_basic_date(t_info *info, int argc, char **argv)
{
	info->argc = argc - 1;
	info->argc_hoge = argc - 1;
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
	set_basic_date(&info, argc, argv);
	stack_argv(&info);
	is_sorted(&info);
	check_duplicate(&info);
	if (info.argc == 2)
		sort_case_2(&info);
	else if (info.argc == 3)
		sort_case_3(&info);
	else if (info.argc <= 6)
		sort_case_under_6(&info);
	else if(info.argc >= 7)
		sort_case_over7(&info);
//	stack_debug(&info);
	free_element(&info);
	return (0);
}

