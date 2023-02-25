/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehasalu <ehasalu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 20:01:32 by ehasalu           #+#    #+#             */
/*   Updated: 2023/02/25 22:01:39 by ehasalu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <limits.h>


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

int scan_stack(t_stack **lst, int *array, int direction)
{
	int	i;
	int	l;

	l = 1;
	if (direction == 1)
	{
		while (l <= lst_len(*lst))
		{
			i = 0;
			while (array[i] != '\0')
			{
				if (vop(lst, l) == array[i])
					return(array[i]);
				i++;
			}
			l++;
		}
	}
	else
	{
		l = lst_len(*lst);
		while (l > 0)
		{
			i = 0;
			while (array[i] != '\0')
			{
				if (vop(lst, l) == array[i])
					return(array[i]);
				i++;
			}
			l--;
		}
	}
	return (INT_MIN);
}

int	find_pos(t_stack **lst, int num)
{
	int	i;

	i = 1;
	while (1 < lst_len(*lst))
	{
		if (vop(lst, i) == num)
			return (i);
		i++;
	}
	return (0);
}

int	**create_arrays_big(t_stack **a)
{
	int	i;
	int	num;
	int	*arr;
	int	**arrays;
	int	l;
	int	k;

	i = 1;
	num = highest(a);
	arr = malloc(sizeof(int) * lst_len(*a) + 1);
	arr[lst_len(*a) - i] = num;
	while (i < lst_len(*a))
	{
		i++;
		arr[lst_len(*a) - i] = sn_lowest((a), num);
		num = sn_lowest((a), num);
	}
	arr[lst_len(*a)] = '\0';
	i = 0;
	arrays = malloc(sizeof(int*) * 12);
	k = 0;
	while (i < 10)
	{
		l = 0;
		arrays[i] = malloc(sizeof(int) * lst_len(*a)/11);
		while (l < lst_len(*a)/11)
		{
			arrays[i][l] = arr[k];
			//printf("ARR %d: %d\n", i, arrays[i][l]);
			k++;
			l++;
		}
		arrays[i][l] = '\0';
		i++;
	}
	arrays[i] = malloc(sizeof(int) * ((lst_len(*a) - (lst_len(*a)/11) * 10)));
	l = 0;
	while (l < (lst_len(*a) - (lst_len(*a)/11) * 10))
	{
			arrays[i][l] = arr[k];
			//printf("ARR %d: %d\n", i, arrays[i][l]);
			k++;
			l++;
	}
	arrays[i][l] = '\0';
	return (arrays);
}

int	**create_arrays(t_stack **a)
{
	int	i;
	int	num;
	int	*arr;
	int	**arrays;
	int	l;
	int	k;

	i = 1;
	num = highest(a);
	arr = malloc(sizeof(int) * lst_len(*a) + 1);
	arr[lst_len(*a) - i] = num;
	while (i < lst_len(*a))
	{
		i++;
		arr[lst_len(*a) - i] = sn_lowest((a), num);
		num = sn_lowest((a), num);
	}
	arr[lst_len(*a)] = '\0';
	i = 0;
	arrays = malloc(sizeof(int*) * 6);
	k = 0;
	while (i < 4)
	{
		l = 0;
		arrays[i] = malloc(sizeof(int) * lst_len(*a)/5);
		while (l < lst_len(*a)/5)
		{
			arrays[i][l] = arr[k];
			//printf("ARR %d: %d\n", i, arrays[i][l]);
			k++;
			l++;
		}
		arrays[i][l] = '\0';
		i++;
	}
	arrays[i] = malloc(sizeof(int) * ((lst_len(*a) - (lst_len(*a)/5) * 4)));
	l = 0;
	while (l < (lst_len(*a) - (lst_len(*a)/5 * 4)))
	{
			arrays[i][l] = arr[k];
			//printf("ARR %d: %d\n", i, arrays[i][l]);
			k++;
			l++;
	}
	arrays[i][l] = '\0';
	return (arrays);
}

void	move_to_top(t_stack **lst, int num, char stack_l)
{
	if (find_pos(lst, num) > (lst_len(*lst) / 2))
	{
		while (vop(lst, 1) != num)
		{
			if (stack_l == 'a')
				rra(lst);
			else
				rrb(lst);
		}
	}
	else
	{
		while (vop(lst, 1) != num)
		{	
			if (stack_l == 'a')
				ra(lst);
			else
				rb(lst);
		}
	}
}

int closest2(t_stack **lst, int num)
{
	int	i;
	int	res;

	i = 1;
	res = INT_MAX;
	while (i <= lst_len(*lst))
	{
		if (vop(lst, i) > num && vop(lst, i) < res)
			res = vop(lst, i);
		i++;
	}
	return (res);
}

int	low_big_or(t_stack **lst, int num)
{
	if (num > highest(lst))
		return(1);
	else if (num < lowest(lst))
		return (-1);
	else
		return (0);
}

void	move_b(t_stack **b, int num)
{
	if (low_big_or(b, num) == 1)
		move_to_top(b, lowest(b), 'b');
	else if ((low_big_or(b, num) == -1))
		move_to_top(b, lowest(b), 'b');
	else
		move_to_top(b, closest2(b, num), 'b');
}

int lst_print(t_stack *lst_a, t_stack *lst_b)
{
    printf("-----------------\n");
    while (lst_a || lst_b)
    {
        if (lst_a)
            printf("  %-10i", ( lst_a->content));
        else
            printf("%12s", "");
        if (lst_b)
            printf("%-10i\n", ( lst_b->content));
        else
            printf("\n");
        if (lst_a)
            lst_a = lst_a->next;
        if (lst_b)
            lst_b = lst_b->next;
    }
    printf("-----------------\n");
    printf("  %s\t    %s  \n", "a", "b");
    printf("-----------------\n\n");
    return (0);
}

void	over_hun(t_stack **a, t_stack **b, int **sep)
{
	int	hold_first;
	int	hold_second;
	int	mov_num;
	static int i;

	hold_first = scan_stack(a, sep[i], 1);
	hold_second = scan_stack(a, sep[i], 0);
	if ((find_pos(a, hold_first) - 1) < (lst_len(*a) - find_pos(a, hold_second)))
		mov_num = hold_first;
	else
		mov_num = hold_second;
	move_to_top(a, mov_num, 'a');
	if (lst_len(*b))
		move_b(b, mov_num);
	pb(a, b);
	if (scan_stack(a, sep[i], 1) == INT_MIN && i < 11)
		i++;
	if (i == 11)
		return ;
	over_hun(a, b, sep);
}

void	under_hun(t_stack **a, t_stack **b, int **sep)
{
	int	hold_first;
	int	hold_second;
	int	mov_num;
	static int i;

	hold_first = scan_stack(a, sep[i], 1);
	hold_second = scan_stack(a, sep[i], 0);
	if ((find_pos(a, hold_first) - 1) < (lst_len(*a) - find_pos(a, hold_second)))
		mov_num = hold_first;
	else
		mov_num = hold_second;
	move_to_top(a, mov_num, 'a');
	if (lst_len(*b))
		move_b(b, mov_num);
	pb(a, b);
	if (scan_stack(a, sep[i], 1) == INT_MIN && i < 5)
		i++;
	if (i == 5)
		return ;
	under_hun(a, b, sep);
}

void	sort_push_b(t_stack **a, t_stack **b)
{
	while (vop(b, 1) != highest(b))
	{
		move_to_top(b, highest(b), 'b');
	}
	pa(a, b);
}

int main(int argc, char **argv)
{
	int	i;
	t_stack	*a;
	t_stack	*b;
	t_stack	*temp;
	int	**sep;


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
	if (lst_len(a) <= 100)
		sep = create_arrays(&a);
	else
		sep = create_arrays_big(&a);
	if (lst_len(a) == 1)
	  	return (0);
	else if (lst_len(a) <= 5)
	   	under_five(&a, &b);
	else if (lst_len(a) <= 100)
	{
		under_hun(&a, &b, sep);
		while (!b_is_empty(&b))
			sort_push_b(&a, &b);
	}
	else
	{
		over_hun(&a, &b, sep);
		while (!b_is_empty(&b))
			sort_push_b(&a, &b);
	}
		//under_hun(&a, &b, sep);
	//create_arrays(&a);


	printf("Stack A: ");
	while (a != NULL)
	{
		printf("%d ", a->content);
		a = a->next;
	}
	printf("\n");
	printf("Stack B: ");
	while (b != NULL)
	{
		printf("%d ", b->content);
		b = b->next;
	}
//	lst_print(a, b);


}
