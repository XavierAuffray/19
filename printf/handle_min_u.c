/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_min_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xauffray <xauffray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 11:08:59 by xauffray          #+#    #+#             */
/*   Updated: 2021/04/26 11:09:00 by xauffray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static t_flag	run_shit(t_flag flag, int len, unsigned int y)
{
	int	x;
	int	z;

	x = 0;
	z = 0;
	if ((flag.zero > len) && y < 0 && !flag.dot)
		z = 1;
	while (flag.min - only_positive(flag.zero - len) - x++ - len - z > 0)
	{
		ft_putchar_fd(' ', 1);
		flag.counter++;
	}
	if ((!flag.zero && !flag.dot) || (flag.noprint && y)
		|| (flag.dot && !flag.zero && !flag.minus
			&& !flag.special && !flag.regular && y))
	{
		ft_putuint(y);
		flag.counter += uint_len(y);
	}
	if (flag.dot && !flag.zero && !y)
	{
		ft_putchar_fd(' ', 1);
		flag.counter++;
	}
	return (flag);
}

t_flag	handle_min_u(t_flag flag, void *current)
{
	int	y;
	int	len;

	y = *(unsigned int *)&current;
	len = uint_len(y);
	flag = run_shit(flag, len, y);
	return (flag);
}
