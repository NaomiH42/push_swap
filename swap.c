/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehasalu <ehasalu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 19:58:33 by ehasalu           #+#    #+#             */
/*   Updated: 2023/02/21 18:10:07 by ehasalu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **list)
{
	char	*temp;
	
	temp = (*list)->content;
	(*list)->content = ((*list)->next)->content;
	((*list)->next)->content = temp;
}

void	sa(t_list **a)
{
	swap(a);
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_list **b)
{
	swap(b);
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_list **a, t_list **b)
{
	swap(a);
	swap(b);
	ft_putstr_fd("ss\n", 1);
}
