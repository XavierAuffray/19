#include "push_swap.h"

int	stack_is_ordered(t_value *stack_a)
{
	int	x;

	x = 0;
	while (++x < stack_a[0].value)
		if (stack_a[x].value > stack_a[x + 1].value)
			return (0);
	return (1);
}

t_value	*dup_list(t_value *stack)
{
	int		index;
	t_value	*new_list;

	index = 0;
	new_list = (t_value *)malloc(sizeof(t_value) * (stack[0].value + 1));
	if (!new_list)
		return (NULL);
	while (index <= stack[0].value)
	{
		new_list[index].value = stack[index].value;
		index++;
	}
	return (new_list);
}

void	assign_index(t_value *stack_a)
{
	t_value	*ordered_list;
	int		x;
	int		y;

	x = 0;
	y = 1;
	ordered_list = dup_list(stack_a);
	if (!ordered_list)
		return ;
	ordered_list = bbsort_list(ordered_list);
	while (y <= stack_a[0].value)
	{
		while (x < ordered_list[0].value && y <= stack_a[0].value)
		{
			if (stack_a[x + 1].value == ordered_list[y].value)
			{
				stack_a[x + 1].index = y;
				y++;
			}
			x++;
		}
		x = 0;
	}
	free(ordered_list);
}

int	get_number_of_bits(t_value *stack_a)
{
	int	x;
	int	y;

	x = 1;
	y = 0;
	while (stack_a[x].index != stack_a[0].value)
		x++;
	while (stack_a[x].index >> y != 0)
		y++;
	return (y);
}

void	radix(t_value **stack_a, t_value **stack_b)
{
	int		x;
	int		y;
	int		number_of_bits;
	int		size;

	size = (*stack_a)[0].value;
	number_of_bits = get_number_of_bits(*stack_a);
	x = 0;
	y = 0;
	while (x < number_of_bits && !stack_is_ordered(*stack_a))
	{
		while (y < size)
		{
			if (((*stack_a)[1].index >> x) & 1)
				rotate(stack_a, 'a');
			else
				push(stack_a, stack_b, 'b');
			y++;
		}
		while ((*stack_b)[0].value)
			push(stack_b, stack_a, 'a');
		y = 0;
		x++;
	}
}
