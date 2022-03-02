#include "../includes/push_swap.h"

void	error_message(t_info *info)
{
	ft_putendl_fd("error", STDERR_FILENO);
	free_element(info);
}