/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_flag_minus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xauffray <xauffray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 11:10:12 by xauffray          #+#    #+#             */
/*   Updated: 2021/04/26 11:10:13 by xauffray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static t_flag	handle_star(t_flag flag, va_list params)
{
	void	*current;

	current = va_arg(params, int *);
	if (*(int *)&current < 0)
		*(int *)&current *= -1;
	flag.minus = *(int *)&current;
	flag.special = 1;
	flag.str += 2;
	flag.type = *(flag.str);
	return (flag);
}

static t_flag	help_number(t_flag flag, int x)
{
	int	z;

	z = ft_atoi(flag.str + 1);
	flag.minus = z;
	if (*(flag.str + x) != '%')
	{
		flag.str += x + 1;
		flag.special = 1;
	}
	else
		flag.str += x;
	flag.type = *(flag.str);
	return (flag);
}

static t_flag	help_number2(t_flag flag, int x)
{
	int	z;

	z = ft_atoi(flag.str);
	flag.minus = z;
	flag.str += x - 1;
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
	if (*(flag.str + 1) == '0' && ft_strchr("123456789", *(flag.str + 2)))
		flag = help_number3(flag, x);
	else if (ft_strchr(".-0", *(flag.str + 1)))
		flag.str += 1;
	else if (!x)
	{
		flag.type = *(++flag.str);
		flag.regular = 1;
	}
	else if (ft_strchr("cspdiuxX%.", *(flag.str + y - 1)))
		flag = help_number(flag, x);
	else if (ft_strchr("123456789", *(flag.str + 1)))
		flag = help_number2(flag, x);
	return (flag);
}

t_flag	is_flag_minus(t_flag flag, va_list params)
{
	if (*flag.str == '-')
	{
		if (*(flag.str + 1) == '*')
			flag = handle_star(flag, params);
		else
			flag = handle_number(flag);
	}
	return (flag);
}
