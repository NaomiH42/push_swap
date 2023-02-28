#include "push_swap.h"

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
	aaa->len = lst_len(*a) / 5;
	aaa->len_last = (lst_len(*a) - ((lst_len(*a) / 5) * 4));
	while (i < 4)
	{
		l = 0;
		arrays[i] = ft_calloc(sizeof(int), ((lst_len(*a)/5) + 1));
		while (l < lst_len(*a)/5)
		{
			arrays[i][l] = arr[k];
			k++;
			l++;
		}
		i++;
	}
	arrays[i] = ft_calloc(sizeof(int), ((lst_len(*a) - (lst_len(*a)/5) * 4) + 1));
	l = 0;
	while (l < (lst_len(*a) - (lst_len(*a)/5 * 4)))
	{
			arrays[i][l] = arr[k];
			k++;
			l++;
	}
	free(arr);
	return (arrays);
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
		return (1);
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


// int lst_print(t_stack *lst_a, t_stack *lst_b)
// {
//     printf("-----------------\n");
//     while (lst_a || lst_b)
//     {
//         if (lst_a)
//             printf("  %-10i", ( lst_a->content));
//         else
//             printf("%12s", "");
//         if (lst_b)
//             printf("%-10i\n", ( lst_b->content));
//         else
//             printf("\n");
//         if (lst_a)
//             lst_a = lst_a->next;
//         if (lst_b)
//             lst_b = lst_b->next;
//     }
//     printf("-----------------\n");
//     printf("  %s\t    %s  \n", "a", "b");
//     printf("-----------------\n\n");
//     return (0);
// }
