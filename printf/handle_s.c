/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xauffray <xauffray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 11:09:23 by xauffray          #+#    #+#             */
/*   Updated: 2021/04/26 11:09:24 by xauffray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static t_flag	handle_dot(t_flag flag, void *current)
{
	int	x;

	x = 0;
	while (flag.dot - x++ > 0 && *(char *)current)
	{
		ft_putchar_fd(*(char *)current++, 1);
		flag.counter++;
	}
	return (flag);
}

static t_flag	handle_min(t_flag flag, void *current)
{
	int	x;
	int	len;

	len = ft_strlen((char *)current);
	if ((len > flag.dot && flag.dot))
		len = flag.dot;
	if (flag.noprint)
		len = 0;
	x = 0;
	while (flag.min - x++ - len - flag.zero > 0 && !flag.minus)
	{
		ft_putchar_fd(' ', 1);
		flag.counter++;
	}
	if (!flag.dot && !flag.noprint && !flag.minus)
	{
		ft_putstr_fd((char *)current, 1);
		flag.counter += ft_strlen((char *)current);
	}
	return (flag);
}

static t_flag	handle_minus(t_flag flag, void *current)
{
	int	x;
	int	len;

	len = ft_strlen((char *)current);
	if (len > flag.dot && flag.dot)
		len = flag.dot;
	if (flag.noprint)
		len = 0;
	x = 0;
	if (!flag.dot && !flag.noprint && !flag.regular)
	{
		ft_putstr_fd((char *)current, 1);
		flag.counter += ft_strlen((char *)current);
	}
	while (flag.minus - x++ - len > 0)
	{
		ft_putchar_fd(' ', 1);
		flag.counter++;
	}
	return (flag);
}

static t_flag	handle_zero(t_flag flag, void *current)
{
	int	x;
	int	len;

	len = ft_strlen((char *)current);
	x = 0;
	while (only_positive(flag.zero - len) - x++ > 0)
	{
		ft_putchar_fd('0', 1);
		flag.counter++;
	}
	return (flag);
}

t_flag	handle_s(t_flag flag, va_list params)
{
	void	*current;

	if (flag.type == 's')
	{
		current = va_arg(params, char *);
		if (!current)
			current = "(null)";
		if ((flag.regular && !flag.noprint && !flag.min && !flag.dot)
			|| (flag.special && !flag.min && !flag.minus
				&& !flag.regular && !flag.noprint && !flag.dot))
			flag = handle_regular_string(flag, current);
		if (flag.zero)
			flag = handle_zero(flag, current);
		if (flag.min)
			flag = handle_min(flag, current);
		if (flag.dot)
			flag = handle_dot(flag, current);
		if (flag.minus)
			flag = handle_minus(flag, current);
	}
	return (flag);
}
