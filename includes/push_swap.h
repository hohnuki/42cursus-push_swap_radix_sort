#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stdio.h"
# include "stdlib.h"
# include "string.h"
# include "limits.h"
# include "unistd.h"
# include "stdbool.h"
# include "../libft/libft.h"

typedef struct s_stack
{
	int		*a;
	int		*compression_a;
	int		*b;
	int		*compression_b;
	size_t	head_a;
	size_t	head_b;
	size_t	pb_count;
}	t_stack;

typedef struct s_info
{
	size_t	argc;
	size_t	argc_duplicate;
	char	**argv;
	t_stack	stack;
}	t_info;

//stack_debug.c
void	stack_debug(t_info *info);

//stack_argv.c
void	*xmalloc(t_info *info, size_t size);
void	stack_argv(t_info *info);
void	stack_memory_allocate(t_info *info, size_t size);

//one_argument_to_array.c
void	one_argument_to_array(t_info *info);

//compression_array.c
void	compression_array(t_info *info);

//sort_case_2.c
void	sort_case_2(t_info *info);

//sort_case_3.c
void	sort_case_3(t_info *info);
void	sort_case_3_b(t_info *info);

//sort_case_under_6.c
void	sort_case_under_6(t_info *info);

//sort_case_over7.c
void	sort_case_over7(t_info *info);

//operation_swap.c
void	sa(t_info *info);
void	sb(t_info *info);

//operation_rotate.c
void	ra(t_info *info);
void	rb(t_info *info);

//operation_reverse_rotate.c
void	rra(t_info *info);
void	rrb(t_info *info);

//operation_push.c
void	pb(t_info *info);
void	pa(t_info *info);

//ps_atoi.c
int		ps_atoi(const char *str, t_info *info);

//check_duplicate.c
void	check_duplicate(t_info *info);

//is_sorted.c
void	is_sorted(t_info *info);

//error_message.c
void	error_message(t_info *info);

//free.c
void	free_element(t_info *info);

#endif