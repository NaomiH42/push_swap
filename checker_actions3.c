/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_actions3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehasalu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:22:00 by ehasalu           #+#    #+#             */
/*   Updated: 2023/03/13 13:22:01 by ehasalu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	sa_c(t_stack **a)
{
	swap(a);
}

void	sb_c(t_stack **b)
{
	swap(b);
}

void	ss_c(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
}
