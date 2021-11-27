/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_i.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xauffray <xauffray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 11:08:55 by xauffray          #+#    #+#             */
/*   Updated: 2021/04/26 11:08:55 by xauffray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static t_flag	handle_regular(t_flag flag, void *current)
{
	if (!flag.dot && !flag.zero)
	{
		ft_putnbr_fd(*(int *)&current, 1);
		flag.counter += int_len(*(int *)&current);
	}
	return (flag);
}

static t_flag	handle_zero(t_flag flag, void *current)
{
	int	x;
	int	y;
	int	len;

	x = 0;
	y = *(int *)&current;
	len = int_len(y);
	if (y < 0)
	{
		ft_putchar_fd('-', 1);
		y = -y;
		if (flag.dot == 1)
			len -= 1;
	}
	while (flag.zero - x++ - len > 0)
	{
		ft_putchar_fd('0', 1);
		flag.counter++;
	}
	if (y == -2147483648)
		write(1, "2147483648", 10);
	else
		ft_putnbr_fd(y, 1);
	flag.counter += int_len(*(int *)&current);
	return (flag);
}

static t_flag	handle_minus(t_flag flag, void *current)
{
	int	x;
	int	y;
	int	z;
	int	len;

	x = 0;
	y = *(int *)&current;
	len = int_len(y);
	z = inc_z_id_minus(flag, len, y);
	if ((!flag.zero && !flag.dot) || (!flag.zero && y != 0))
	{
		ft_putnbr_fd(y, 1);
		flag.counter += int_len(*(int *)&current);
	}
	while (flag.minus - only_positive(flag.zero - len) - x++ - len - z > 0)
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
	int	z;
	int	len;

	x = 0;
	y = *(int *)&current;
	len = int_len(y);
	z = inc_z_id_min(flag, len, y);
	while (flag.min - only_positive(flag.zero - len) - x++ - len - z > 0)
	{
		ft_putchar_fd(' ', 1);
		flag.counter++;
	}
	if (!flag.zero && !flag.dot)
	{
		ft_putnbr_fd(y, 1);
		flag.counter += int_len(*(int *)&current);
	}
	return (flag);
}

t_flag	handle_i(t_flag flag, va_list params)
{
	void	*current;

	if (ft_include("id", flag.type))
	{
		current = va_arg(params, int *);
		if (flag.min)
			flag = handle_min(flag, current);
		if ((flag.regular && !flag.minus && !flag.min)
			|| (flag.special && !flag.zero && !flag.minus && !flag.dot))
			flag = handle_regular(flag, current);
		if (flag.zero)
			flag = handle_zero(flag, current);
		if (flag.minus)
			flag = handle_minus(flag, current);
		if (flag.dot && !flag.zero && *(int *)&current != 0 && !flag.minus)
		{
			ft_putnbr_fd(*(int *)&current, 1);
			flag.counter += int_len(*(int *)&current);
		}
	}
	return (flag);
}
