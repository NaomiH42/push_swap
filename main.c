/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehasalu <ehasalu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 20:01:32 by ehasalu           #+#    #+#             */
/*   Updated: 2023/02/22 16:17:24 by ehasalu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>


int	calc_medi(t_stack **a)
{
	int	i;
	int	num;
	int	*arr;
	int	res;

	i = 1;
	num = highest(a);
	arr = malloc(sizeof(int) * lst_len(*a));
	arr[lst_len(*a) - i] = num;
	while (i < lst_len(*a))
	{
		i++;
		arr[lst_len(*a) - i] = sn_lowest((a), num);
		num = sn_lowest((a), num);
	}
	arr[lst_len(*a)] = '\0';
	if (lst_len(*a) % 2 != 0)
		res = arr[lst_len(*a) / 2];
	else
	{
		res = (arr[(lst_len(*a) / 2)] + arr[(lst_len(*a) / 2 ) - 1]) / 2;
	}
	free(arr);
	return (res);
}

void	assign_med(t_stack **a)
{
	t_stack	*temp;

	temp = *a;
	while (temp != NULL)
	{
		if (temp->content <= calc_medi(a))
			temp->med = 1;
		else
			temp->med = 2;
		temp = temp->next;
	}
}

int	high_med(t_stack **a)
{
	t_stack	*temp;

	temp = *a;
	while (temp != NULL)
	{
		if (temp->med == 1)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	put_a_to_b (t_stack **a, t_stack **b)
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

void	under_hun(t_stack **a, t_stack **b)
{
	if (vom(a, 1) == 1)
	{
		if (b_is_empty(b))
		{	
			pb(a, b);
			under_hun(a, b);
		}
		else
		{
			if (vop(a, 1) > lowest(b))
			{
				while (vop(b, lst_len(*b)) != sn_lowest(b, vop(a, 1)))
					rb(b);
			}
			else
			{
				while (vop(b, 1) != lowest(b))
				rb(b);
			}
			pb(a, b);
			under_hun(a, b);
		}
	}
	else if (vom(a, 1) == 2 && high_med(a))
	{
		while (vop(b, 1) != lowest(b))
			rb(b);
		put_a_to_b(a, b);
		while (vop(b, 1) != highest(b))
			rb(b);
		while (!b_is_empty(b))
		{
			pa(a, b);
			if (!b_is_empty(b))
				rrb(b);
		}
	}
	// else
	// 	ra(a);
	// if (b_is_empty(a))
	// {
	// 	while (vop(b, 1) != lowest(b))
	// 	{
	// 		rb(b);
	// 	}
	// 	while (!b_is_empty(b))
	// 		pa(a, b);
	// }
}

int main(int argc, char **argv)
{
	// int	argc = 9;
	// char **argv = ft_split("0 2 3 1 4 5 9 11 15", ' ');

	int	i;
	t_stack	*a;
	t_stack	*b;
	t_stack	*temp;

	i = 1;
	a = malloc(sizeof *a);
	a->content = ft_atoi(argv[i]);
	a->med = 0;
	temp = a;
	b = NULL;
	i++;
    while (i < argc)
	{
		temp->next = malloc(sizeof *a);
		temp = temp->next;
		temp->content = ft_atoi(argv[i]);
		temp->med = 0;
		i++;
	}
	assign_med(&a);
	if (lst_len(a) == 1)
	  	return (0);
	else if (lst_len(a) <= 5)
	   	under_five(&a, &b);
	else// if (lst_len(a) <= 100)
		under_hun(&a, &b);
	// printf("Stack A: ");
	// while (a != NULL)
	// {
	// 	printf("%d ", a->content);
	// 	a = a->next;
	// }
	// printf("\n");
	// printf("Stack B: ");
	// while (b != NULL)
	// {
	// 	printf("%d ", b->content);
	// 	b = b->next;
	// }
	
	
}
