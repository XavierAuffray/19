#include "push_swap.h"
#include "stdio.h"

static int	write_and_return_one(void)
{
	write(2, "Error\n", 6);
	return (1);
}

int	an_error_occured(char **argv, int argc)
{
	int	x;
	int	y;

	x = 1;
	if (!argv[1])
		return (1);
	while (x < argc)
	{
		y = 0;
		if (*argv[x] == '-' && !ft_isnum(*(argv[x] + 1)))
			return (write_and_return_one());
		while (argv[x][y])
		{
			if (argv[x][1] == '-' && !ft_isnum(argv[x][y + 1]))
				return (write_and_return_one());
			if (!ft_isnum(argv[x][y]) && argv[x][0] != '-')
				return (write_and_return_one());
			y++;
		}
		x++;
	}
	return (0);
}

int	doublon_in_stack(t_value *stack)
{
	int	x;
	int	y;

	x = 1;
	y = 2;
	while (x <= stack[0].value - 1)
	{
		while (y <= stack[0].value)
		{
			if (stack[x].value == stack[y].value)
			{				
				write(2, "Error\n", 6);
				return (1);
			}
			y++;
		}
		x += 1;
		y = x + 1;
	}
	return (0);
}

int	over_min_max_values(t_value *stack)
{
	int	x;

	x = 0;
	while (x <= stack[0].value)
	{
		if (stack[x].value > 2147483647 || stack[x].value < -2147483648)
		{
			write(2, "Error\n", 6);
			return (1);
		}
		x++;
	}
	return (0);
}
