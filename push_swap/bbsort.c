#include "push_swap.h"

void	swap_values(long *x, long *y)
{
	long	temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

t_value	*bbsort_list(t_value *stack)
{
	int	x;
	int	y;

	x = 1;
	y = 2;
	while (x < stack[0].value)
	{
		while (y < stack[0].value + 1)
		{
			if (stack[x].value > stack[y].value)
				swap_values(&(stack[x].value), &(stack[y].value));
			y++;
		}
		y = x + 1;
		x++;
	}
	return (stack);
}
