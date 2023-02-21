
#include "push_swap.h"

void	reverse_rotate(t_list **stack)
{
	t_list	*temp;
	t_list	*cur;

	temp = *stack;
	while ((temp->next)->next != NULL)
	{
		temp = temp->next;
	}
	cur = temp->next;
	temp->next = NULL;
	cur->next = *stack;
	*stack = cur;
}

void    rra(t_list **a)
{
    reverse_rotate(a);
    ft_putstr_fd("rra\n", 1);
}

void	rrb(t_list **b)
{
	reverse_rotate(b);
	ft_putstr_fd("rbr\n", 1);
}

void	rrr(t_list **a, t_list **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_putstr_fd("rrr\n", 1);
}