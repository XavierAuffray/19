#include "push_swap.h"

void	swap(t_value **stack, int ref)
{
	t_value	temp_1;
	t_value	temp_2;

	if (!(*stack)[0].value || (*stack)[0].value == 1)
		return ;
	if (ref == 'a')
		write(1, "sa\n", 3);
	else if (ref == 'b')
		write(1, "sb\n", 3);
	temp_1.value = (*stack)[1].value;
	temp_2.value = (*stack)[2].value;
	(*stack)[1].value = temp_2.value;
	(*stack)[2].value = temp_1.value;
}

static void	push_msg(int ref)
{
	if (ref == 'a')
		write(1, "pa\n", 3);
	else if (ref == 'b')
		write(1, "pb\n", 3);
}

void	push(t_value **stack_src, t_value **stack_dest, int ref)
{
	t_value	temp;
	long	len;
	long	x;

	if (!(*stack_src)[0].value)
		return ;
	push_msg(ref);
	len = (*stack_dest)[0].value + 1;
	temp = (*stack_src)[1];
	while (--len)
		(*stack_dest)[len + 1] = (*stack_dest)[len];
	(*stack_dest)[1].value = temp.value;
	(*stack_dest)[1].index = temp.index;
	(*stack_dest)[0].value += 1;
	x = 1;
	while (x < (*stack_src)[0].value)
	{
		(*stack_src)[x].value = (*stack_src)[x + 1].value;
		(*stack_src)[x].index = (*stack_src)[x + 1].index;
		x++;
	}
	(*stack_src)[0].value -= 1;
}

void	rotate(t_value **stack, int ref)
{
	t_value	len;
	t_value	temp;
	long	x;

	if (!(*stack)[0].value)
		return ;
	if (ref == 'a')
		write(1, "ra\n", 3);
	else if (ref == 'b')
		write(1, "rb\n", 3);
	x = 1;
	len = (*stack)[0];
	temp = (*stack)[1];
	while (x < len.value)
	{
		(*stack)[x] = (*stack)[x + 1];
		x++;
	}
	(*stack)[x] = temp;
}

void	reverse_rotate(t_value **stack, int ref)
{
	long	len;
	long	temp;

	if (!(*stack)[0].value)
		return ;
	if (ref == 'a')
		write(1, "rra\n", 4);
	else if (ref == 'b')
		write(1, "rrb\n", 4);
	len = (*stack)[0].value;
	temp = (*stack)[len].value;
	while (len)
	{
		(*stack)[len].value = (*stack)[len - 1].value;
		len--;
	}
	(*stack)[1].value = temp;
}
