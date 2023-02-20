/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehasalu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 19:58:28 by ehasalu           #+#    #+#             */
/*   Updated: 2023/02/10 19:58:30 by ehasalu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	push(t_list **a, t_list **b)
{
	t_list	*temp;

	temp = (*a)->next;
	(*a)->next = *b;
	*b = *a;
	*a = temp;
}

void	pa(t_list **a, t_list **b)
{
	push(a, b);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_list **a, t_list **b)
{
	push(b, a);
	ft_putstr_fd("pb\n", 1);
}
