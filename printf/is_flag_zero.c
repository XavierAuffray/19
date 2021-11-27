/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_flag_zero.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xauffray <xauffray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 11:10:15 by xauffray          #+#    #+#             */
/*   Updated: 2021/04/26 11:10:16 by xauffray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static t_flag	handle_star(t_flag flag, va_list params)
{
	void	*current;

	current = va_arg(params, int *);
	if (*(int *)&current < 0)
		flag.minus = *(int *)&current * -1;
	else
	{
		flag.zero = *(int *)&current;
		flag.min = *(int *)&current;
		flag.special = 1;
	}
	flag.str += 2;
	flag.type = *flag.str;
	return (flag);
}

static t_flag	help_number(t_flag flag)
{
	while (*flag.str++ == '0')
		flag.type = *flag.str;
	flag.regular = 1;
	flag.str--;
	return (flag);
}

static t_flag	help_number2(t_flag flag, int x)
{
	int	z;

	z = ft_atoi(flag.str);
	flag.zero = z;
	flag.min = z;
	flag.str += x + 1;
	flag.type = *flag.str;
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
	if (*(flag.str + 1) == '0')
		flag = help_number(flag);
	else if (!x && *(flag.str + y - 1) != '-')
	{
		flag.regular = 1;
		flag.str += 1;
		flag.type = *flag.str;
	}
	else if (!x && *(flag.str + y - 1) == '-')
		flag.str += 1;
	else if (ft_strchr("cspdiuxX%.", *(flag.str + y - 1)))
		flag = help_number2(flag, x);
	return (flag);
}

t_flag	is_flag_zero(t_flag flag, va_list params)
{
	if (*flag.str == '0')
	{
		if (*(flag.str + 1) == '*')
			flag = handle_star(flag, params);
		else
			flag = handle_number(flag);
	}
	return (flag);
}
