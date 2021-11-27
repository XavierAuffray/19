#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_value		*stack_a;
	t_value		*stack_b;

	if (an_error_occured(argv, argc))
		return (0);
	stack_a = create_stack_a(argc, argv);
	if (!stack_a)
		return (0);
	stack_b = create_stack_b(argc);
	if (!stack_b)
		return (free_stack_a(&stack_a));
	if (doublon_in_stack(stack_a) || over_min_max_values(stack_a))
		return (free_stacks(&stack_a, &stack_b));
	assign_index(stack_a);
	if (stack_a[0].value > 5)
		radix(&stack_a, &stack_b);
	else
		make_a_magic_trick(&stack_a, &stack_b);
	free_stacks(&stack_a, &stack_b);
	return (0);
}
