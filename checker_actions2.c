/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_actions2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehasalu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:21:56 by ehasalu           #+#    #+#             */
/*   Updated: 2023/03/13 13:21:57 by ehasalu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ra_c(t_stack **a)
{
	rotate(a);
}

void	rb_c(t_stack **b)
{
	rotate(b);
}

void	rr_c(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
}
