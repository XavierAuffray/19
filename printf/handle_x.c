/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xauffray <xauffray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 11:09:38 by xauffray          #+#    #+#             */
/*   Updated: 2021/04/26 11:09:38 by xauffray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static t_flag	handle_regular(t_flag flag, void *current)
{
	if ((flag.dot && !*(unsigned int *)&current) || flag.noprint)
		return (flag);
	print_hexa(*(unsigned int *)&current, 'x');
	flag.counter += flag.hexa_length;
	return (flag);
}

static t_flag	handle_zero(t_flag flag, void *current)
{
	int	x;
	int	y;

	x = 0;
	y = *(unsigned int *)&current;
	while (flag.zero - x++ - flag.hexa_length > 0)
	{
		ft_putchar_fd('0', 1);
		flag.counter++;
	}
	print_hexa(y, 'x');
	flag.counter += flag.hexa_length;
	return (flag);
}

static t_flag	handle_minus(t_flag flag, void *current)
{
	int	x;
	int	y;
	int	z;

	x = 0;
	y = *(unsigned int *)&current;
	z = inc_z_x_minus(flag, y);
	if ((!flag.zero && !flag.dot) || (flag.noprint && y)
		|| (flag.dot && !flag.zero && y))
	{
		print_hexa(y, 'x');
		flag.counter += flag.hexa_length;
	}
	while (flag.minus - only_positive(flag.zero - flag.hexa_length)
		- x++ - flag.hexa_length - z > 0)
	{
		ft_putchar_fd(' ', 1);
		flag.counter++;
	}
	return (flag);
}

static t_flag	handle_min(t_flag flag, void *current)
{
	int	x;
	int	y;

	x = 0;
	y = *(unsigned int *)&current;
	while (flag.min - only_positive(flag.zero - flag.hexa_length)
		- x++ - flag.hexa_length > 0)
	{
		ft_putchar_fd(' ', 1);
		flag.counter++;
	}
	if ((!flag.zero && !flag.dot) || (flag.noprint && y)
		|| (flag.dot && !flag.zero && !flag.minus && y))
	{
		print_hexa(y, 'x');
		flag.counter += flag.hexa_length;
	}
	if (flag.dot && !flag.zero && !y)
	{
		ft_putchar_fd(' ', 1);
		flag.counter++;
	}
	return (flag);
}

t_flag	handle_x(t_flag flag, va_list params)
{
	void	*current;

	if (flag.type == 'x')
	{
		current = va_arg(params, unsigned int *);
		flag = ft_hexa_length(flag, *(unsigned int *)&current);
		if (flag.min)
			flag = handle_min(flag, current);
		if (flag.regular && !flag.zero && !flag.minus && !flag.min)
			flag = handle_regular(flag, current);
		if (flag.zero)
			flag = handle_zero(flag, current);
		if (flag.minus)
			flag = handle_minus(flag, current);
		flag = others_x(flag, current);
	}
	return (flag);
}
