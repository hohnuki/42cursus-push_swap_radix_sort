#include "../includes/push_swap.h"

void	free_element(t_info *info)
{
	if (info->stack.a != NULL)
		free(info->stack.a);
	if (info->stack.compression_a != NULL)
		free(info->stack.compression_a);
	if (info->stack.b != NULL)
		free(info->stack.b);
	if (info->stack.compression_b != NULL)
		free(info->stack.compression_b);
}
