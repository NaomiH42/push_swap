
#include "push_swap.h"

void	put_a_to_b(t_stack **a, t_stack **b)
{
	while (!b_is_empty(a))
	{
		while (vop(a, 1) != highest(a))
			ra(a);
		pb(a, b);
	}
}

void	put_b_to_a(t_stack **a, t_stack **b)
{
	if (!b_is_empty(b))
	{
		while (vop(b, 1) != highest(b))
			rb(b);
		pa(a, b);
	}
}

int	scan_stack(t_stack **lst, int *array, int direction, int aaa)
{
	int	i;
	int	l;

	l = 1;
	if (direction == 1)
	{
		while (l <= lst_len(*lst))
		{
			i = 0;
			while (i < aaa)
			{
				if (vop(lst, l) == array[i])
					return (array[i]);
				i++;
			}
			l++;
		}
	}
	else
	{
		l = lst_len(*lst);
		while (l > 0)
		{
			i = 0;
			while (i < aaa)
			{
				if (vop(lst, l) == array[i])
					return (array[i]);
				i++;
			}
			l--;
		}
	}
	return (DW_ABOUT_IT);
}

int	find_pos(t_stack **lst, int num)
{
	int	i;

	i = 1;
	while (i <= lst_len(*lst))
	{
		if (vop(lst, i) == num)
			return (i);
		i++;
	}
	return (0);
}

void	move_to_top(t_stack **lst, int num, char stack_l)
{
	if (find_pos(lst, num) > (lst_len(*lst) / 2))
	{
		while (vop(lst, 1) != num)
		{
			if (stack_l == 'a')
				rra(lst);
			else
				rrb(lst);
		}
	}
	else
	{
		while (vop(lst, 1) != num)
		{
			if (stack_l == 'a')
				ra(lst);
			else
				rb(lst);
		}
	}
}
