#include "../includes/push_swap.h"

static void	bubble_sort(t_info *info, int *array)
{
	size_t	i;
	size_t	j;
	int		tmp;

	i = 0;
	tmp = 0;
	while (i < info->argc)
	{
		j = i;
		while (j < info->argc)
		{
			if (array[i] > array[j])
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

static void	stack_a_duplicate(t_info *info, int *array)
{
	size_t	i;

	i = 0;
	while (i < info->argc)
	{
		array[i] = info->stack.a[i];
		i++;
	}
}

void	compression_array(t_info *info)
{
	int		*array;
	size_t	array_i;
	size_t	sa_i;

	array = xmalloc(info, sizeof(int) * info->argc);
	stack_a_duplicate(info, array);
	bubble_sort(info, array);
	array_i = 0;
	while (array_i < info->argc)
	{
		sa_i = 0;
		while (sa_i < info->argc)
		{
			if (array[array_i] == info->stack.a[sa_i])
				info->stack.compression_a[sa_i] = array_i;
			sa_i++;
		}
		array_i++;
	}
	free (array);
}
