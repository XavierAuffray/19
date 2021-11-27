/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xauffray <xauffray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 11:10:58 by xauffray          #+#    #+#             */
/*   Updated: 2021/04/26 11:10:59 by xauffray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_flag	others_x(t_flag flag, void *current)
{
	if ((flag.dot && !flag.min && !flag.zero && !flag.regular && !flag.minus
			&& *(unsigned int *)&current && !flag.noprint)
		|| (flag.noprint && flag.dot && !flag.minus
			&& !flag.min && *(unsigned int *)&current)
		|| (flag.special && !flag.minus && !flag.zero
			&& !flag.dot && !flag.regular))
	{
		print_hexa(*(unsigned int *)&current, 'x');
		flag.counter += flag.hexa_length;
	}
	return (flag);
}

t_flag	others_xx(t_flag flag, void *current)
{
	if ((flag.dot && !flag.min && !flag.zero && !flag.regular && !flag.minus
			&& *(unsigned int *)&current && !flag.noprint)
		|| (flag.noprint && flag.dot && !flag.minus
			&& !flag.min && *(unsigned int *)&current)
		|| (flag.special && !flag.minus && !flag.zero
			&& !flag.dot && !flag.regular))
	{
		print_hexa(*(unsigned int *)&current, 'X');
		flag.counter += flag.hexa_length;
	}
	return (flag);
}
