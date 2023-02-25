/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehasalu <ehasalu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 20:01:32 by ehasalu           #+#    #+#             */
/*   Updated: 2023/02/22 16:17:24 by ehasalu          ###   ########.fr       */
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

void	move_to_top(t_stack **a, int num)
{
	if (find_pos(a, num) > (lst_len(*a) / 2))
	{
		while (vop(a, 1) != num)
			rra(a);
	}
	else
	{
		while (vop(a, 1) != num)
			ra(a);
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
		move_to_top(b, lowest(b));
	else if ((low_big_or(b, num) == -1))
		move_to_top(b, lowest(b));
	else
		move_to_top(b, closest2(b, num));
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
	//printf("%d", mov_num);
	move_to_top(a, mov_num);
	if (lst_len(*b))
		move_b(b, mov_num);
	pb(a, b);
	if (scan_stack(a, sep[i], 1) == INT_MIN && i < 5)
		i++;
	if (i == 5)
		return ;
	//lst_print(*a, *b);
	under_hun(a, b, sep);
	//printf("%d ", find_pos(a, hold_first));
	//printf("%d", find_pos(a, hold_second));

	// if (vom(a, 1) == 1)
	// {
	// 	if (b_is_empty(b))
	// 	{
	// 		pb(a, b);
	// 		under_hun(a, b);
	// 	}
	// 	else
	// 	{
	// 		if (vop(a, 1) > lowest(b))
	// 		{
	// 			while (vop(b, lst_len(*b)) != sn_lowest(b, vop(a, 1)))
	// 				rb(b);
	// 		}
	// 		else
	// 		{
	// 			while (vop(b, 1) != lowest(b))
	// 			rb(b);
	// 		}
	// 		pb(a, b);
	// 		under_hun(a, b);
	// 	}
	// }
	// else if (vom(a, 1) == 2 && high_med(a))
	// {
	// 	while (vop(b, 1) != lowest(b))
	// 		rb(b);
	// 	put_a_to_b(a, b);
	// 	while (vop(b, 1) != highest(b))
	// 		rb(b);
	// 	while (!b_is_empty(b))
	// 	{
	// 		pa(a, b);
	// 		if (!b_is_empty(b))
	// 			rrb(b);
	// 	}
	// }
	// else
	// 	ra(a);
	// if (b_is_empty(a))
	// {
	// 	while (vop(b, 1) != lowest(b))
	// 	{
	// 		rb(b);
	// 	}
	// 	while (!b_is_empty(b))
	// 		pa(a, b);
	// }
}

void	sort_push_b(t_stack **a, t_stack **b)
{
	while (vop(b, 1) != highest(b))
	{
		move_to_top(b, highest(b));
	}
	pa(a, b);
}

int main(int argc, char **argv)
{
	// int	argc = 9;
	// char **argv = ft_split("0 2 3 1 4 5 9 11 15", ' ');

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
	sep = create_arrays(&a);
	// assign_med(&a);
	if (lst_len(a) == 1)
	  	return (0);
	else if (lst_len(a) <= 5)
	   	under_five(&a, &b);
	else// if (lst_len(a) <= 100)
	{
		under_hun(&a, &b, sep);
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
