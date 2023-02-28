#include "push_swap.h"

int half_p(t_stack **a, int num)
{
	int	i;
	int	res;

	res = 0;
	i = 1;
	while (i <= lst_len(*a))
	{
		if (vop(a, i) == num)
		{
			res = lst_len(*a) % i;
			if (res > lst_len(*a) / 2)
				return (0);
			else
				return (1);
		}
		i++;
	}
	return (1);
}

int closest3(t_stack **lst, int num)
{
	int	i;
	int	res;

	i = 1;
	res = highest(lst);
	while (i <= lst_len(*lst))
	{
		if (vop(lst, i) > num && vop(lst, i) < res)
			res = vop(lst, i);
		i++;
	}
	return (res);
}

void	under_five(t_stack **a, t_stack **b)
{
	if (lst_len(*a) < 3)
	{
		if (vop(a, 1) > vop(a, 2))
			sa(a);
	}
	else if (lst_len(*a) == 3)
		algorithm_stuff(a, 1);
	else
	{
		while (lst_len(*a) != 3)
			pb(a, b);
		algorithm_stuff(a, 1);
		while (!b_is_empty(b))
		{
			if (vop(b, 1) > highest(a))
			{
				move_to_top(a, lowest(a), 'a');
			}
			else if(vop(b, 1) < lowest(a))
					move_to_top(a, lowest(a), 'a');
			else
					move_to_top(a, closest3(a, vop(b, 1)), 'a');
			pa(a, b);
		}
		while (vop(a, 1) != lowest(a))
			ra(a);
	}
}
