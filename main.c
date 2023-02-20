/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehasalu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 20:01:32 by ehasalu           #+#    #+#             */
/*   Updated: 2023/02/10 20:01:59 by ehasalu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"
#include <stdio.h>

void	rotate(t_list **stack)
{
	t_list	*temp;
	t_list	*cur;

	cur = *stack;
	temp = *stack;
	while (cur->next != NULL)
	{
		printf("%s", cur->content);
		cur = cur->next;
	}
	temp->next = NULL;
	cur->next = temp;
}

int main(int argv, char **argc)
{
	int	i;
	t_list	*a;
	t_list	*b;

	i = 1;
	a = ft_lstnew(argc[i]);
	b = ft_lstnew(NULL);
    	while (argv > 1)
	{
	 	ft_lstadd_front(&a, ft_lstnew(argc[argv -1]));
	 	argv--;
		i++;
	}
	//sa(&a);
	//push(&a, &b);
	rotate(&a);
	while (a->next != NULL)
	{
		printf("%s", a->content);
		a = a->next;
	}
	printf("\n");
	while (b->next != NULL)
	{
		printf("%s", b->content);
		b = b->next;
	}
	
	
}
