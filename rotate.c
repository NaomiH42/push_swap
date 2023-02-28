#include "push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*cur;

	temp = *stack;
	cur = get_last(*stack);
	*stack = (*stack)->next;
	temp->next = NULL;
	cur->next = temp;
}

void    ra(t_stack **a)
{
    rotate(a);
   	ft_putstr_fd("ra\n", 1);
}

void	rb(t_stack **b)
{
	rotate(b);
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	ft_putstr_fd("rr\n", 1);
}
