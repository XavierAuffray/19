/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xauffray <xauffray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 11:08:47 by xauffray          #+#    #+#             */
/*   Updated: 2021/04/26 11:08:47 by xauffray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static t_flag	handle_regular(t_flag flag, void *current)
{
	ft_putchar_fd(*(int *)&current, 1);
	return (flag);
}

static t_flag	handle_min(t_flag flag, void *current)
{
	int	x;

	x = 0;
	while (flag.min - x++ - 1 > 0)
	{
		ft_putchar_fd(' ', 1);
		flag.counter++;
	}
	ft_putchar_fd(*(int *)&current, 1);
	return (flag);
}

static t_flag	handle_minus(t_flag flag, void *current)
{
	int	x;

	x = 0;
	ft_putchar_fd(*(int *)&current, 1);
	while (flag.minus - x++ - 1 > 0)
	{
		ft_putchar_fd(' ', 1);
		flag.counter++;
	}
	return (flag);
}

t_flag	handle_c(t_flag flag, va_list params)
{
	void	*current;

	if (flag.type == 'c')
	{
		current = va_arg(params, char *);
		if ((flag.regular && !flag.minus && !flag.min)
			|| (flag.special && !flag.min && flag.zero && !flag.minus))
			flag = handle_regular(flag, current);
		if (flag.minus)
			flag = handle_minus(flag, current);
		if (flag.min)
			flag = handle_min(flag, current);
		if (flag.special && !flag.zero && !flag.minus
			&& !flag.min && !flag.regular)
			ft_putchar_fd(*(int *)&current, 1);
		flag.counter++;
	}
	return (flag);
}
