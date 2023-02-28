#include "push_swap.h"

void	free_array(int ***arr, int flag)
{
	int	i;

	i = 0;
	if (flag)
	{
		while (i < 5)
		{
			free((*arr)[i]);
			i++;
		}
		free(*arr);
	}
	else
	{
		while (i < 11)
		{
			free((*arr)[i]);
			i++;
		}
		free(*arr);
	}
}

void	free_stuff(int ***arr, t_stack **a)
{
	t_stack	*temp;

	temp = *a;
	if (lst_len(*a) <= 100 && lst_len(*a) > 5)
		free_array(arr, 1);
	else if (lst_len(*a) > 100)
		free_array(arr, 0);
	while (*a != NULL)
	{
		temp = (*a)->next;
		free(*a);
		*a = temp;
	}
}
