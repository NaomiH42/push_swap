#include "push_swap.h"

void	rotate(t_list **stack)
{
	t_list	*temp;
	t_list	*cur;

	temp = *stack;
	*stack = (*stack)->next;
	temp->next = NULL;
	ft_lstadd_back(stack, temp);
}

void    ra(t_list **a)
{
    rotate(a);
    ft_putstr_fd("ra\n", 1);
}

void	rb(t_list **b)
{
	rotate(b);
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_list **a, t_list **b)
{
	rotate(a);
	rotate(b);
	ft_putstr_fd("rr\n", 1);
}