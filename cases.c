#include "push_swap.h"


int	case1(t_stack **a)
{
	if (vop(a, 1) > vop(a, 2) && vop(a, 1) < vop(a, 3))
		return (1);
	return (0);
}

int	case2(t_stack **a)
{
	if (vop(a, 1) > vop(a, 2) && vop(a, 2) > vop(a, 3))
		return (1);
	return (0);
}

int	case3(t_stack **a)
{
	if (vop(a, 1) > vop(a, 2) && vop(a, 2) < vop(a, 3)
		&& vop(a, 1) > vop(a, 3))
		return (1);
	return (0);
}

int	case4(t_stack **a)
{
	if (vop(a, 1) < vop(a, 2) && vop(a, 2) > vop(a, 3)
		&& vop(a, 1) < vop(a, 3))
		return (1);
	return (0);
}

int	case5(t_stack **a)
{
	if (vop(a, 1) < vop(a, 2) && vop(a, 2) > vop(a, 3)
		&& vop(a, 3) < vop(a, 1))
		return (1);
	return (0);
}