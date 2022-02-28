#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "limits.h"
#include "unistd.h"
#include "../libft//libft.h"

typedef struct s_stack
{
	int	*a;
	int	*compression_a;
	int *b;
	int *compression_b;
	int head_a;
	int head_b;
}	t_stack;

typedef struct s_info
{
	int		argc;
	char	**argv;
	t_stack	stack;
}	t_info;

//main.c

//stack_debug.c
void	stack_debug(t_info *info);

//sort_case_over7.c
void	sort_case_over7(t_info *info);

//operation_rotate.c

//operation_push.c

#endif