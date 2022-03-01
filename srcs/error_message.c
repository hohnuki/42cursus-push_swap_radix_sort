#include "../includes/push_swap.h"

void	error_message(t_info *info, char *message)
{
	ft_putendl_fd(message, 2);
	free_element(info);
}