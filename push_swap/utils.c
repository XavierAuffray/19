#include "push_swap.h"

void	handle_three(t_value **stack_a, t_value **stack_b, int ref)
{
	t_value	**stack;

	if (ref == 'a')
		stack = stack_a;
	else
		stack = stack_b;
	while (!stack_is_ordered(*stack) && (*stack)[0].value < 4)
	{
		if ((*stack)[1].value > (*stack)[2].value
			&& (*stack)[1].value > (*stack)[3].value)
			rotate(stack, ref);
		else if ((*stack)[1].value > (*stack)[2].value)
			swap(stack, ref);
		else if ((*stack)[1].value > (*stack)[(*stack)[0].value].value)
			reverse_rotate(stack, ref);
		else if ((*stack)[2].value > (*stack)[3].value)
		{
			rotate(stack, ref);
			swap(stack, ref);
		}
	}
}

void	rr_and_p(t_value **stack_a, t_value **stack_b, int rr, int p)
{
	if (rr == 'b')
		reverse_rotate(stack_b, rr);
	else if (rr == 'a')
		reverse_rotate(stack_a, rr);
	if (p == 'a')
		push(stack_b, stack_a, p);
	else if (p == 'b')
		push(stack_a, stack_b, p);
}

void	s_and_p(t_value **stack_a, t_value **stack_b, int s, int p)
{
	if (s == 'a')
		swap(stack_a, s);
	else if (s == 'b')
		swap (stack_b, s);
	if (p == 'b')
		push(stack_a, stack_b, p);
	else if (p == 'a')
		push(stack_b, stack_a, p);
}
