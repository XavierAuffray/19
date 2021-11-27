/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xauffray <xauffray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 11:09:30 by xauffray          #+#    #+#             */
/*   Updated: 2021/04/26 11:09:32 by xauffray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static t_flag	handle_regular(t_flag flag, void *current)
{
	if ((flag.dot && !*(unsigned int *)&current)
		|| (flag.special && *(unsigned int *)&current))
		return (flag);
	ft_putuint(*(unsigned int *)&current);
	flag.counter += uint_len(*(unsigned int *)&current);
	return (flag);
}

static t_flag	handle_zero(t_flag flag, void *current)
{
	int	x;
	int	y;
	int	len;

	x = 0;
	y = *(unsigned int *)&current;
	len = uint_len(y);
	while (flag.zero - x++ - len > 0)
	{
		ft_putchar_fd('0', 1);
		flag.counter++;
	}
	ft_putuint(y);
	flag.counter += uint_len(*(unsigned int *)&current);
	return (flag);
}

static t_flag	handle_minus(t_flag flag, void *current)
{
	int	x;
	int	y;
	int	z;
	int	len;

	x = 0;
	z = 0;
	y = *(unsigned int *)&current;
	len = uint_len(y);
	if ((flag.zero > len && y && !flag.dot) || (flag.dot && !flag.zero && y))
		z++;
	if (flag.dot && !flag.zero)
		z--;
	if ((!flag.zero && !flag.dot)
		|| (flag.minus && flag.dot && !flag.zero && y))
	{
		ft_putuint(y);
		flag.counter += uint_len(*(unsigned int *)&current);
	}
	while (flag.minus - only_positive(flag.zero - len) - x++ - len - z > 0)
	{
		ft_putchar_fd(' ', 1);
		flag.counter++;
	}
	return (flag);
}

t_flag	handle_u(t_flag flag, va_list params)
{
	void	*current;

	if (flag.type == 'u')
	{
		current = va_arg(params, unsigned int *);
		if (flag.min)
			flag = handle_min_u(flag, current);
		if (flag.regular && !flag.min && !flag.minus && !flag.zero)
			flag = handle_regular(flag, current);
		if (flag.zero)
			flag = handle_zero(flag, current);
		if (flag.minus)
			flag = handle_minus(flag, current);
		if ((flag.dot && !flag.min && !flag.zero && !flag.minus
				&& !flag.regular && *(unsigned int *)&current)
			|| (flag.special && !flag.zero
				&& !flag.minus && *(unsigned int *)&current && !flag.noprint)
			|| (flag.special && !flag.zero
				&& !flag.minus && !flag.dot && !flag.regular))
		{
			ft_putuint(*(unsigned int *)&current);
			flag.counter += uint_len(*(unsigned int *)&current);
		}
	}
	return (flag);
}
