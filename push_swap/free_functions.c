#include "push_swap.h"

int	free_stacks(t_value **stack_a, t_value **stack_b)
{
	free(*stack_a);
	free(*stack_b);
	return (0);
}

int	free_stack_a(t_value **stack)
{
	free(*stack);
	return (0);
}
