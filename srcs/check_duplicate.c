#include "../includes/push_swap.h"

void	check_duplicate(t_info *info)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < info->argc)
	{
		j = 0;
		while (j < info->argc)
		{
			if (j == i)
			{
				j++;
				continue ;
			}
			if (info->stack.a[i] == info->stack.a[j])
			{
				error_message(info);
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
}
