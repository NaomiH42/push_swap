#include "push_swap.h"

int half_p(t_stack **a, int num)
{
	int	i;
	int	res;

	res = 0;
	i = 1;
	while (i < lst_len(*a))
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


void	under_five(t_stack **a, t_stack **b)
{
	if (lst_len(*a) < 3)
	{
		if (vop(a, 1) > vop(a, 2))
			sa(a);
	}
	else if (lst_len(*a) == 3)
	{
		algorithm_stuff(a);
	}
	else
	{
		while (lst_len(*a) != 3)
			pb(a, b);
		algorithm_stuff(a);
		while (lst_len(*b) != 0)
		{
			if (vop(b, 1) > highest(a))
			{
				while (vop(a, 1) != lowest(a))
					ra(a);
				pa(a, b);
				ra(a);
			}
			else if (vop(b, 1) < lowest(a))
			{
				while (vop(a, 1) != lowest(a))
				{
					if (half_p(a, lowest(a)) == 0)
						rra(a);
					else
						ra(a);
				}
				pa(a, b);
			}
			else
			{
				while (vop(a, lst_len(*a)) != sn_lowest(a, vop(b, 1)))
				{
					if (half_p(a, lowest(a)) == 0)
						rra(a);
					else
						ra(a);
				}
				pa(a, b);
				while (!a_is_sort(a))
				{
					if (half_p(a, lowest(a)) == 0)
						ra(a);
					else
						rra(a);
				}
			}
		}

	}
}
