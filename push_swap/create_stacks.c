#include "push_swap.h"

t_value	*create_stack_a(int counter, char **argv)
{
	long	index;
	t_value	*stack;

	index = 0;
	stack = (t_value *)malloc(sizeof(t_value) * counter);
	if (!stack)
		return (NULL);
	stack[index++].value = counter - 1;
	while (index < counter)
	{
		stack[index].value = ft_atoi(argv[index]);
		index++;
	}
	return (stack);
}

t_value	*create_stack_b(int counter)
{
	t_value	*stack;

	stack = (t_value *)malloc(sizeof(t_value) * counter);
	if (!stack)
		return (NULL);
	stack[0].value = 0;
	return (stack);
}
