/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_actions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehasalu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:21:53 by ehasalu           #+#    #+#             */
/*   Updated: 2023/03/13 13:21:54 by ehasalu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	pa_c(t_stack **a, t_stack **b)
{
	push(b, a);
}

void	pb_c(t_stack **a, t_stack **b)
{
	push(a, b);
}

void	rra_c(t_stack **a)
{
	reverse_rotate(a);
}

void	rrb_c(t_stack **b)
{
	reverse_rotate(b);
}

void	rrr_c(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}
