/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_flag_dot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xauffray <xauffray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 11:10:05 by xauffray          #+#    #+#             */
/*   Updated: 2021/04/26 11:10:05 by xauffray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static t_flag	handle_star(t_flag flag, va_list params)
{
	void	*current;

	current = va_arg(params, int *);
	if (*(int *)&current < 0)
		flag.regular = 1;
	else
	{
		if (ft_strchr("iduxX", *(flag.str + 2)))
		{
			flag.zero = *(int *)&current;
			flag.dot = 1;
		}
		else
		{
			if (*(int *)&current != 0)
				flag.dot = *(int *)&current;
			else
				flag.noprint = 1;
		}
	}
	flag.str += 2;
	flag.type = *flag.str;
	return (flag);
}

static t_flag	help_number(t_flag flag, int x)
{
	int	z;

	z = ft_atoi(flag.str + 1);
	if (ft_strchr("piduxX", *(flag.str + x + 1)))
	{
		flag.zero = z;
		flag.dot = 1;
	}
	else
		flag.dot = z;
	if (!x || !z)
		flag.noprint = 1;
	flag.str += x + 1;
	flag.type = *(flag.str);
	if (flag.type == 'c')
		flag.regular = 1;
	return (flag);
}

static t_flag	handle_number(t_flag flag)
{
	int	x;
	int	y;

	x = 0;
	y = 1;
	while (ft_isnum(*(flag.str + y++)))
		x++;
	if (ft_strchr("cspdiuxX%.-", *(flag.str + y - 1)))
		flag = help_number(flag, x);
	return (flag);
}

t_flag	is_flag_dot(t_flag flag, va_list params)
{
	if (*flag.str == '.')
	{
		if (*(flag.str + 1) == '*')
			flag = handle_star(flag, params);
		else
			flag = handle_number(flag);
	}
	return (flag);
}
