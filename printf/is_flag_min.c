/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_flag_min.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xauffray <xauffray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 11:10:08 by xauffray          #+#    #+#             */
/*   Updated: 2021/04/26 11:10:09 by xauffray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static t_flag	handle_star(t_flag flag, va_list params)
{
	void	*current;

	current = va_arg(params, int *);
	if (!*(int *)&current)
		flag.regular = 1;
	else
	{
		if (*(int *)&current > 0)
			flag.min = *(int *)&current;
		else
			flag.minus = *(int *)&current * -1;
	}
	flag.str += 1;
	flag.type = *flag.str;
	return (flag);
}

static t_flag	handle_number(t_flag flag)
{
	int	x;
	int	y;
	int	z;

	x = 0;
	y = 0;
	while (ft_isnum(*(flag.str + y++)))
		x++;
	if (ft_strchr("cspdiuxX%.", *(flag.str + y - 1)))
	{
		z = ft_atoi(flag.str);
		flag.min = z;
		if (*(flag.str - 1) == '0' && *(flag.str + y - 1) != 's')
			flag.zero = z;
		flag.str += x;
		flag.type = *(flag.str);
	}
	return (flag);
}

t_flag	is_flag_min(t_flag flag, va_list params)
{
	if (ft_strchr("123456789*", *flag.str))
	{
		if (*(flag.str) == '*')
			flag = handle_star(flag, params);
		else
			flag = handle_number(flag);
	}
	return (flag);
}
