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

int	check_arg(int argc, char **argv)
{
	int	i;
	int j;
	int	k;

	i = 1;
	while (i < argc)
	{
		j = i+1;
		k = 1;
		while (argv[i][k])
		{
			if (argv[i][0] != '-' && (argv[i][0] < '0' || argv[i][0] > '9'))
			{
				ft_printf("Invalid argument");
				exit(0);
			}
			if (argv[i][k] < '0' || argv[i][k] > '9')
			{
				ft_printf("Invalid argument");
				exit(0);
			}
			k++;
		}
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
			{
				ft_printf("Identical arguments");
				exit(0);
			}
			j++;
		}
		i++;
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

int scan_stack(t_stack **lst, int *array, int direction, int aaa)
{
	int	i;
	int	l;

	l = 1;
	if (direction == 1)
	{
		while (l <= lst_len(*lst))
		{
			i = 0;
			//ft_printf("ARRAY: %d\nlist %d\n", array[i], vop(lst,l));
			while (i < aaa)
			{
				//ft_printf("ARRAY: %d\nlist %d\n", array[i], vop(lst,l));
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
			while (i < aaa)
			{
				if (vop(lst, l) == array[i])
					return(array[i]);
				i++;
			}
			l--;
		}
	}
	return (DW_ABOUT_IT);
}

int	find_pos(t_stack **lst, int num)
{
	int	i;

	i = 1;
	while (i <= lst_len(*lst))
	{
		if (vop(lst, i) == num)
			return (i);
		i++;
	}
	return (0);
}

int	**create_arrays_big(t_stack **a, t_size *aaa)
{
	int	i;
	int	num;
	int	*arr;
	int	**arrays;
	int	l;
	int	k;

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
	i = 0;
	arrays = ft_calloc(sizeof(int*), 11);
	k = 0;
	aaa->len = lst_len(*a)/11;
	aaa->len_last = (lst_len(*a) - ((lst_len(*a)/11) * 10));
	while (i < 10)
	{
		l = 0;
		arrays[i] = malloc(sizeof(int)* ((lst_len(*a)/11)));
		while (l < lst_len(*a)/11)
		{
			arrays[i][l] = arr[k];
			k++;
			l++;
		}
		i++;
	}
	arrays[i] = malloc(sizeof(int) * (((lst_len(*a) - (lst_len(*a)/11) * 10))));
	l = 0;
	while (l < (lst_len(*a) - (lst_len(*a)/11) * 10))
	{
			arrays[i][l] = arr[k];
			k++;
			l++;
	}
	free(arr);
	return (arrays);
}

int	**create_arrays(t_stack **a, t_size *aaa)
{
	int	i;
	int	num;
	int	*arr;
	int	**arrays;
	int	l;
	int	k;

	i = 1;
	num = highest(a);
	arr = ft_calloc(sizeof(int), lst_len(*a));
	arr[lst_len(*a) - i] = num;
	while (i < lst_len(*a))
	{
		i++;
		arr[lst_len(*a) - i] = sn_lowest((a), num);
		num = sn_lowest((a), num);
	}
	i = 0;
	arrays = malloc(sizeof(int*) * 6);
	k = 0;
	aaa->len = lst_len(*a)/5;
	aaa->len_last = (lst_len(*a) - ((lst_len(*a)/5) * 4));
	while (i < 4)
	{
		l = 0;
		arrays[i] = ft_calloc(sizeof(int), ((lst_len(*a)/5) + 1));
		while (l < lst_len(*a)/5)
		{
			arrays[i][l] = arr[k];
			//printf("ARR %d: %d\n", i, arrays[i][l]);
			k++;
			l++;
		}
		//arrays[i][l] = DW_ABOUT_IT;
		i++;
	}
	arrays[i] = ft_calloc(sizeof(int), ((lst_len(*a) - (lst_len(*a)/5) * 4) + 1));
	l = 0;
	while (l < (lst_len(*a) - (lst_len(*a)/5 * 4)))
	{
			arrays[i][l] = arr[k];
			//printf("ARR %d: %d\n", i, arrays[i][l]);
			k++;
			l++;
	}
	//arrays[i][l] = DW_ABOUT_IT;
	free(arr);
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
	res = highest(lst);
	while (i < lst_len(*lst))
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

void	over_hun(t_stack **a, t_stack **b, int **sep, t_size aaa)
{
	int	hold_first;
	int	hold_second;
	int	mov_num;
	static int i;
	int	bbb;

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
	//printf("%d\n", mov_num);
	move_to_top(a, mov_num, 'a');
	if (lst_len(*b))
		move_b(b, mov_num);
	pb(a, b);
	//lst_print(*a, *b);
	if (scan_stack(a, sep[i], 1, bbb) == DW_ABOUT_IT && i < 11)
		i++;
	if (i == 11)
		return ;
	//lst_print(*a, *b);
	over_hun(a, b, sep, aaa);
}

void	under_hun(t_stack **a, t_stack **b, int **sep, t_size aaa)
{
	int	hold_first;
	int	hold_second;
	int	mov_num;
	static int i;
	int	bbb;

	if (i == 4)
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

void	free_stuff(int ***arr, t_stack **a)
{
	int	i;
	t_stack *temp;

	temp = *a;
	i = 0;
	if (lst_len(*a) <= 100 && lst_len(*a) > 5)
	{
		while (i < 5)
		{
			free((*arr)[i]);
			i++;
		}
		free(*arr);
	}
	else if (lst_len(*a) > 100)
	{
		while (i < 11)
		{
			free((*arr)[i]);
			i++;
		}
		free(*arr);
	}
	//free(*arr);
	while (*a != NULL)
	{
		temp = (*a)->next;
		free(*a);
		*a = temp;
	}
}

int main(int argc, char **argv)
{
	//int argc = 6;
	//char *argv[6] = {"0", "4", "3", "1", "5", "2"};//"-439", "-157", "97", "341", "272", "-320", "312", "44", "85", "-189", "-365", "154", "218", "14", "-34", "-200", "370", "133", "-364", "233", "261", "449", "212", "-480", "143", "130", "-70", "-359", "-210", "205", "98", "167", "6", "333", "313", "-110", "-177", "299", "-347", "-197", "-455", "387", "-13", "117", "134", "298", "-427", "-246", "-278", "-47", "-418", "-331", "495", "334", "-49", "-280", "-295", "-89", "-204", "-312", "-369", "102", "-293", "184", "123", "-257", "317", "-22", "-315", "210", "-153", "-385", "108", "104", "-387", "-41", "319", "142", "-375", "-360", "52", "260", "466", "-207", "135", "38", "176", "-326", "-468", "277", "-83", "139", "467", "120", "-294", "330", "440", "327", "81", "160"};//"0", "89", "76", "82", "11", "70"};//, "88", "17", "8", "18", "38", "34", "41", "27", "23", "71", "39", "16", "90", "66", "100", "63", "99", "54", "30", "2", "78", "44", "36", "33", "5", "43", "21", "22", "84", "10", "73", "80", "25", "62", "86", "58", "7", "57", "31", "94", "60", "9", "35", "3", "77", "46", "48", "12", "91", "15", "65", "4", "1", "69", "28", "13", "92", "67", "61", "98", "56", "79", "68", "74", "37", "32", "97", "95", "40", "47", "29", "24", "42", "26", "52", "50", "59", "55", "20", "64", "85", "19", "75", "6", "83", "14", "81", "72", "93", "45", "51", "49", "53", "87", "96", "222", "481"};

	int	i;
	t_stack	*a;
	t_stack	*b;
	t_stack	*temp;
	int	**sep;
	t_size aaa;

	check_arg(argc, argv);
	i = 1;
	a = malloc(sizeof *a);
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
	if (lst_len(a) <= 100 && lst_len(a) > 5)
		sep = create_arrays(&a, &aaa);
	else if (lst_len(a) > 100)
		sep = create_arrays_big(&a, &aaa);


	if (lst_len(a) == 1)
	  	return (0);
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
	//lst_print(a, b);
	free_stuff(&sep, &a);
		//under_hun(&a, &b, sep);
	//create_arrays(&a);


	// printf("Stack A: ");
	// while (a != NULL)
	// {
	// 	printf("%d ", a->content);
	// 	a = a->next;
	// }
	// printf("\n");
	// printf("Stack B: ");
	// while (b != NULL)
	// {
	// 	printf("%d ", b->content);
	// 	b = b->next;
	// }



}