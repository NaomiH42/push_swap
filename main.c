/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehasalu <ehasalu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 20:01:32 by ehasalu           #+#    #+#             */
/*   Updated: 2023/02/21 20:57:39 by ehasalu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	vop(t_list **lst, int pos)
{
	int	i;
	t_list *temp;

	i = 1;
	temp = *lst;
	while (i != pos)
	{
		temp = temp->next;
		i++;
	}
	return (ft_atoi(temp->content));
}


int	lst_len(t_list **lst)
{
	t_list *temp;
	int	i;

	i = 0;
	temp = lst;
	while (temp->next != NULL)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

int	b_is_empty(t_list **b)
{
	if (*b!= NULL)
		return (0);
	return (1);
}
int	a_is_sort(t_list **a)
{
	int	i;

	i = 1;
	while (i < lst_len(a))
	{
		if (vop(a, i) > vop(a, i + 1))
			return (0);
		i++;
	}
	return (1);
}

void	algorithm_stuff(t_list **a, t_list **b)
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

int	highest(t_list **lst)
{
	int num;
	int	i;

	i = 1;
	num = 0;
	while (i <= lst_len(lst))
	{
		if (vop(lst, i) > num)
			num = vop(lst, i);
		i++;
	}
	return (num);
}

int closest(t_list **lst, int num)
{
	int	i;

	i = 1;
	while (i < lst_len(lst))
	{
		if (vop(lst, i) < num && vop(lst, i + 1) > num)
			return (vop(lst, i + 1));
		i++;
	}
	return (highest(lst));
}

int	lowest(t_list **lst)
{
	int num;
	int	i;

	i = 1;
	num = vop(lst, i);
	while (i <= lst_len(lst))
	{
		if (vop(lst, i) < num)
			num = vop(lst, i);
		i++;
	}
	return (num);
}

int main(int argc, char **argv)
{
	int	i;
	t_list	*a;
	t_list	*b;
	int	flag;

	flag = 1;
	i = 1;
	a = ft_lstnew(argv[argc - 1]);
	b = NULL;
	argc--;
    	while (argc > 1)
	{
	 	ft_lstadd_front(&a, ft_lstnew(argv[argc - 1]));
	 	argc--;
		i++;
	}
	// while (!a_is_sort(&a) || !b_is_empty(&b))
	// {
	// 	if (lst_len(&a) == 5)
	// 	{
	// 		pb(&a, &b);
	// 	 	pb(&a, &b);
	// 	 	algorithm_stuff(&a, &b);
	// 	}
		// if (lst_len(&a) == 5 && !a_is_sort(&a) && flag)
		// {	
		// 	pb(&a, &b);
		// 	pb(&a, &b);
		// 	algorithm_stuff(&a, &b);
		// 	flag = 0;
		// }
		// else if (lst_len(&b) == 1 || lst_len(&b) == 2)
		// {
		// 	if (a && b && vop(&b, 1) < lowest(&a))
		// 		pa(&a, &b);
		// 	else if (a && b && vop(&b, 1) > highest(&a))
		// 	{
		// 		pa(&a, &b);
		// 		ra(&a);
		// 	}
		// 	else 
		// 	{
		// 		while (vop(&a, 1) != closest(&a, vop(&b, 1)))
		// 			ra(&a);
		// 		pa(&a, &b);
		// 		while (!a_is_sort(&a))
		// 			ra(&a);
		// 	}
		// }
		// if (lst_len(&a) == 3 && !a_is_sort(&a))
		// 	algorithm_stuff(&a, &b); 
	//}
	algorithm_stuff(&a, &b);
	printf("Stack A: ");
	while (a != NULL)
	{
		printf("%s ", a->content);
		a = a->next;
	}
	printf("\n");
	printf("Stack B: ");
	while (b != NULL)
	{
		printf("%s ", b->content);
		b = b->next;
	}
	
	
}
