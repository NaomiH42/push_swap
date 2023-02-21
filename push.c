/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehasalu <ehasalu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 19:58:28 by ehasalu           #+#    #+#             */
/*   Updated: 2023/02/21 20:10:12 by ehasalu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **a, t_list **b)
{
	t_list	*temp;

	if (*a == NULL)
		return ;
	temp = *a;
	*a = (*a)->next;
	temp->next = *b;
	*b = temp;
}

void	pa(t_list **a, t_list **b)
{
	push(b, a);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_list **a, t_list **b)
{
	push(a, b);
	ft_putstr_fd("pb\n", 1);
}
