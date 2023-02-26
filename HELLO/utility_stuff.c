
#include "push_swap.h"

t_stack *get_last(t_stack *lst)
{
	// if (!lst || !lst->next)
	// 	return (lst);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

int	vop(t_stack **lst, int pos)
{
	int	i;
	t_stack *temp;

	i = 1;
	temp = *lst;
	while (i != pos)
	{
		temp = temp->next;
		i++;
	}
	return (temp->content);
}

int	lst_len(t_stack *lst)
{
	t_stack *temp;
	int	i;

	i = 1;
	if (lst == NULL)
		return (0);
	temp = lst;
	while (temp->next != NULL)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

int	b_is_empty(t_stack **b)
{
	if (*b!= NULL)
		return (0);
	return (1);
}
int	a_is_sort(t_stack **a)
{
	int	i;

	i = 1;
	while (i < lst_len(*a))
	{
		if (vop(a, i) > vop(a, i + 1))
			return (0);
		i++;
	}
	return (1);
}

void	algorithm_stuff(t_stack **a)
{
	if (case1(a))
		sa(a);
	if (case2(a))
	{
		sa(a);
		rra(a);
	}
	if (case3(a))
		ra(a);
	if (case4(a))
	{
		sa(a);
		ra(a);
	}
	if (case5(a))
		rra(a);
}

int	highest(t_stack **lst)
{
	int num;
	int	i;

	i = 1;
	num = INT_MIN;
	while (i <= lst_len(*lst))
	{
		if (vop(lst, i) > num)
			num = vop(lst, i);
		i++;
	}
	return (num);
}

int closest(t_stack **lst, int num)
{
	int	i;

	i = 1;
	while (i < lst_len(*lst))
	{
		if (vop(lst, i) < num && vop(lst, i + 1) > num)
			return (vop(lst, i + 1));
		i++;
	}
	return (highest(lst));
}

int	lowest(t_stack **lst)
{
	int num;
	int	i;

	i = 1;
	num = vop(lst, i);
	while (i <= lst_len(*lst))
	{
		if (vop(lst, i) < num)
			num = vop(lst, i);
		i++;
	}
	return (num);
}

int	sn_lowest(t_stack **lst, int num)
{
	int res;
	int	i;

	i = 1;
	res = INT_MIN;
	while (i <= lst_len(*lst))
	{
		if (vop(lst, i) > res && vop(lst, i) < num)
			res = vop(lst, i);
		i++;
	}
	return (res);
}
