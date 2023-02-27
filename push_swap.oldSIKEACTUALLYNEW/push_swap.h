/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehasalu <ehasalu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 19:58:57 by ehasalu           #+#    #+#             */
/*   Updated: 2023/02/22 15:59:19 by ehasalu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "./libft/libft.h"
#include <limits.h>

#define DW_ABOUT_IT -2147483646

typedef struct s_stack
{
	struct s_stack	*next;
	int			content;
}	t_stack;

typedef struct s_size
{
	int	len;
	int len_last;
}	t_size;

void	swap(t_stack **list);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	push(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	rotate(t_stack **stack);
void    ra(t_stack **a);
void    rb(t_stack **b);
void    rr(t_stack **a, t_stack **b);
void    rra(t_stack **a);
void    rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	reverse_rotate(t_stack **stack);

int	vop(t_stack **lst, int pos);
int	lst_len(t_stack *lst);
int	b_is_empty(t_stack **b);
int	a_is_sort(t_stack **a);
void	algorithm_stuff(t_stack **a, int i);
int	highest(t_stack **lst);
int closest(t_stack **lst, int num);
int	lowest(t_stack **lst);
int	sn_lowest(t_stack **lst, int num);
t_stack *get_last(t_stack *lst);
void	under_five(t_stack **a, t_stack **b);
int half_p(t_stack **a, int num);
void	move_to_top(t_stack **lst, int num, char stack_l);
int lst_print(t_stack *lst_a, t_stack *lst_b);

int	case1(t_stack **a);
int	case2(t_stack **a);
int	case3(t_stack **a);
int	case4(t_stack **a);
int	case5(t_stack **a);



#endif
