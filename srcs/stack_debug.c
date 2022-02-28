#include "../includes/push_swap.h"

void	stack_debug(t_info *info)
{
	int	i;

	i = 0;
	while(i < info->argc)
	{
		printf("%d ", info->stack.a[i]);
		i++;
	}
	printf("\n");
	i = 0;
	while(i < info->argc)
	{
		printf("%d ", info->stack.compression_a[i]);
		i++;
	}
	printf("\n");
}
