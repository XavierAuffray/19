#include "push_swap.h"

static void	move_a_bis(t_value **stack_a, t_value **stack_b)
{
	push(stack_a, stack_b, 'b');
	if ((*stack_b)[(*stack_b)[0].value].value > (*stack_b)[1].value
		&& (*stack_b)[(*stack_b)[0].value].value > (*stack_b)[2].value)
		reverse_rotate(stack_b, 'b');
	else if ((*stack_b)[1].value < (*stack_b)[2].value
		&& (*stack_b)[1].value < (*stack_b)[(*stack_b)[0].value].value)
		rotate(stack_b, 'b');
	else if ((*stack_b)[2].value > (*stack_b)[1].value
		&& (*stack_b)[2].value > (*stack_b)[(*stack_b)[0].value].value)
		swap(stack_b, 'b');
}

static void	move_a(t_value **stack_a, t_value **stack_b)
{
	while ((*stack_a)[0].value && !stack_is_ordered(*stack_a))
	{
		if ((*stack_a)[0].value == 3)
			handle_three(stack_a, stack_b, 'a');
		else if ((*stack_a)[(*stack_a)[0].value].value < (*stack_a)[1].value
			&& (*stack_a)[(*stack_a)[0].value].value < (*stack_a)[2].value)
			rr_and_p(stack_a, stack_b, 'a', 'b');
		else if ((*stack_a)[1].value > (*stack_a)[2].value
			&& (*stack_a)[1].value > (*stack_a)[(*stack_a)[0].value].value)
			rotate(stack_a, 'a');
		else if ((*stack_a)[2].value < (*stack_a)[1].value
			&& (*stack_a)[2].value < (*stack_a)[(*stack_a)[0].value].value)
			s_and_p(stack_a, stack_b, 'a', 'b');
		else if ((*stack_a)[0].value == 2
			&& (*stack_a)[1].value > (*stack_a)[2].value)
			s_and_p(stack_a, stack_b, 'a', 'b');
		else
			move_a_bis(stack_a, stack_b);
	}
}

static void	move_b_bis(t_value **stack_a, t_value **stack_b)
{
	push(stack_b, stack_a, 'a');
	if ((*stack_a)[(*stack_a)[0].value].value < (*stack_a)[1].value
		&& (*stack_a)[(*stack_a)[0].value].value < (*stack_a)[2].value)
		reverse_rotate(stack_a, 'a');
	else if ((*stack_a)[1].value > (*stack_a)[2].value
		&& (*stack_a)[1].value > (*stack_a)[(*stack_a)[0].value].value)
		rotate(stack_a, 'a');
	else if ((*stack_a)[2].value < (*stack_a)[1].value
		&& (*stack_a)[2].value < (*stack_a)[(*stack_a)[0].value].value)
		swap(stack_a, 'a');
}

static void	move_b(t_value **stack_a, t_value **stack_b)
{
	while ((*stack_b)[0].value)
	{
		if ((*stack_b)[(*stack_b)[0].value].value > (*stack_b)[1].value
			&& (*stack_b)[(*stack_b)[0].value].value > (*stack_b)[2].value)
			rr_and_p(stack_a, stack_b, 'b', 'a');
		else if ((*stack_b)[1].value < (*stack_b)[2].value
			&& (*stack_b)[1].value < (*stack_b)[(*stack_b)[0].value].value)
			rotate(stack_b, 'b');
		else if ((*stack_b)[2].value > (*stack_b)[1].value
			&& (*stack_b)[2].value > (*stack_b)[(*stack_b)[0].value].value)
			s_and_p(stack_a, stack_b, 'b', 'a');
		else if ((*stack_b)[0].value == 2
			&& (*stack_b)[1].value < (*stack_b)[2].value)
			s_and_p(stack_a, stack_b, 'b', 'a');
		else
			move_b_bis(stack_a, stack_b);
	}
}

void	make_a_magic_trick(t_value **stack_a, t_value **stack_b)
{
	int	stack_size;

	handle_three(stack_a, stack_b, 'a');
	stack_size = (*stack_a)[0].value;
	while (!stack_is_ordered(*stack_a) || (*stack_a)[0].value != stack_size)
	{
		move_a(stack_a, stack_b);
		move_b(stack_a, stack_b);
	}
}
