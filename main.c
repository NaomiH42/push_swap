/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehasalu <ehasalu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 20:01:32 by ehasalu           #+#    #+#             */
/*   Updated: 2023/02/28 20:41:06 by ehasalu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	over_hun(t_stack **a, t_stack **b, int **sep, t_size aaa)
{
	int			hold_first;
	int			hold_second;
	int			mov_num;
	static int	i;
	int			bbb;

	if (i == 10)
		bbb = aaa.len_last;
	else
		bbb = aaa.len;
	hold_first = scan_stack(a, sep[i], 1, bbb);
	hold_second = scan_stack(a, sep[i], 0, bbb);
	if ((find_pos(a, hold_first) - 1) < (lst_len(*a) - find_pos(a, hold_second)))
		mov_num = hold_first;
	else
		mov_num = hold_second;
	move_to_top(a, mov_num, 'a');
	if (lst_len(*b))
		move_b(b, mov_num);
	pb(a, b);
	if (scan_stack(a, sep[i], 1, bbb) == DW_ABOUT_IT && i < 11)
		i++;
	if (i == 11)
		return ;
	over_hun(a, b, sep, aaa);
}

void	under_hun(t_stack **a, t_stack **b, int **sep, t_size aaa)
{
	int			hold_first;
	int			hold_second;
	int			mov_num;
	static int	i;
	int			bbb;

	if (i == 4)
		bbb = aaa.len_last;
	else
		bbb = aaa.len;
	hold_first = scan_stack(a, sep[i], 1, bbb);
	hold_second = scan_stack(a, sep[i], 0, bbb);
	if ((find_pos(a, hold_first) - 1) <(lst_len(*a) - find_pos(a, hold_second)))
		mov_num = hold_first;
	else
		mov_num = hold_second;
	move_to_top(a, mov_num, 'a');
	if (lst_len(*b))
		move_b(b, mov_num);
	pb(a, b);
	if (scan_stack(a, sep[i], 1, bbb) == DW_ABOUT_IT && i < 5)
		i++;
	if (i == 5)
		return ;
	under_hun(a, b, sep, aaa);
}

void	sort_push_b(t_stack **a, t_stack **b)
{
	while (vop(b, 1) != highest(b))
	{
		move_to_top(b, highest(b), 'b');
	}
	pa(a, b);
}



void	operations(t_stack *a, t_stack *b)
{
	t_size	aaa;
	int		**sep;

	if (lst_len(a) <= 100 && lst_len(a) > 5)
		sep = create_arrays(&a, &aaa);
	else if (lst_len(a) > 100)
		sep = create_arrays_big(&a, &aaa);
	if (lst_len(a) == 1)
		exit(0);
	else if (lst_len(a) <= 5)
		under_five(&a, &b);
	else if (lst_len(a) <= 100)
	{
		under_hun(&a, &b, sep, aaa);
		while (!b_is_empty(&b))
			sort_push_b(&a, &b);
	}
	else
	{
		over_hun(&a, &b, sep, aaa);
		while (!b_is_empty(&b))
			sort_push_b(&a, &b);
	}
	free_stuff(&sep, &a);
}

int	main(int argc, char **argv)
{
	int		i;
	t_stack	*a;
	t_stack	*b;
	t_stack	*temp;

	if (argc == 1)
		return (0);
	check_arg(argc, argv);
	i = 1;
	a = malloc(sizeof(*a));
	a->content = ft_atoi(argv[i]);
	temp = a;
	b = NULL;
	i++;
	while (i < argc)
	{
		temp->next = ft_calloc(sizeof (*a), 1);
		temp = temp->next;
		temp->content = ft_atoi(argv[i]);
		i++;
	}
	operations(a, b);
}
