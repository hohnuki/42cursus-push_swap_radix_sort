#include "../includes/push_swap.h"

static void	bubble_sort(t_info *info, int *array)
{
	size_t	i;
	size_t	j;
	int	tmp;

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

static void	stack_a_to_array(t_info *info, int *array)
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
	int	*array;
	size_t	i;
	size_t	j;

	array = malloc(sizeof(int) * info->argc + 1);
	if (array == NULL)
		free_element(info);
	stack_a_to_array(info, array);
	bubble_sort(info, array);
	i = 0;
	while (i < info->argc)
	{
		j = 0;
		while (j < info->argc)
		{
			if (array[i] == info->stack.a[j])
				info->stack.compression_a[j] = i;
			j++;
		}
		i++;
	}
	free (array);
}
