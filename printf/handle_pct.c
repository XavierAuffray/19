/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xauffray <xauffray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 11:09:14 by xauffray          #+#    #+#             */
/*   Updated: 2021/04/26 11:09:15 by xauffray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static t_flag	handle_regular(t_flag flag)
{
	ft_putchar_fd('%', 1);
	return (flag);
}

static t_flag	handle_min(t_flag flag)
{
	int	x;

	x = 0;
	if (!flag.minus)
	{
		while (flag.min - only_positive(flag.zero - 1) - x++ - 1 > 0)
		{
			ft_putchar_fd(' ', 1);
			flag.counter++;
		}
		ft_putchar_fd('%', 1);
	}
	return (flag);
}

static t_flag	handle_minus(t_flag flag)
{
	int	x;

	x = 0;
	ft_putchar_fd('%', 1);
	while (flag.minus - x++ - 1 > 0)
	{
		ft_putchar_fd(' ', 1);
		flag.counter++;
	}
	return (flag);
}

static t_flag	handle_zero(t_flag flag)
{
	int	x;

	x = 0;
	if (!flag.min)
		ft_putchar_fd('%', 1);
	while (flag.zero - x++ - 1 > 0)
	{
		ft_putchar_fd('0', 1);
		flag.counter++;
	}
	return (flag);
}

t_flag	handle_pct(t_flag flag)
{
	if (flag.type == '%')
	{
		if (flag.regular && !flag.zero && !flag.minus && !flag.dot && !flag.min)
			flag = handle_regular(flag);
		if (flag.zero)
			flag = handle_zero(flag);
		if (flag.min)
			flag = handle_min(flag);
		if (flag.minus)
			flag = handle_minus(flag);
		if ((flag.noprint && !flag.regular
				&& !flag.zero && !flag.minus && !flag.min)
			|| (flag.special && !flag.zero && !flag.minus
				&& !flag.regular && !flag.min)
			|| (flag.dot && !flag.minus && !flag.min && !flag.zero))
			ft_putchar_fd('%', 1);
		flag.counter++;
	}
	return (flag);
}
