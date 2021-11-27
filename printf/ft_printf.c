/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xauffray <xauffray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 11:08:38 by xauffray          #+#    #+#             */
/*   Updated: 2021/04/26 11:08:39 by xauffray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static	t_flag	initialize_flag(t_flag flag)
{
	flag.regular = 0;
	flag.zero = 0;
	flag.minus = 0;
	flag.dot = 0;
	flag.type = 0;
	flag.min = 0;
	flag.hexa_length = 0;
	flag.noprint = 0;
	flag.special = 0;
	return (flag);
}

static t_flag	fill_flag(t_flag flag, va_list params)
{
	int	x;

	if (*flag.str == '%')
	{
		flag.str++;
		flag = is_regular(flag);
		x = 0;
		while (!ft_strchr("cspdiuxX%", *flag.str))
		{
			if (x == 50)
				break ;
			flag = is_flag_min(flag, params);
			flag = is_flag_zero(flag, params);
			flag = is_flag_minus(flag, params);
			flag = is_flag_dot(flag, params);
			x++;
		}
		if (flag.type)
			flag.str++;
	}
	return (flag);
}

static t_flag	dispay_flag(t_flag flag, va_list params)
{
	flag = handle_c(flag, params);
	flag = handle_i(flag, params);
	flag = handle_s(flag, params);
	flag = handle_u(flag, params);
	flag = handle_x(flag, params);
	flag = handle_X(flag, params);
	flag = handle_p(flag, params);
	flag = handle_pct(flag);
	return (flag);
}

static int	ft_router(va_list params, const char *format)
{
	t_flag	flag;

	flag.str = (char *)format;
	flag.counter = 0;
	while (*flag.str)
	{
		if (*flag.str == '%')
		{
			flag = initialize_flag(flag);
			flag = fill_flag(flag, params);
			flag = dispay_flag(flag, params);
		}
		else
		{
			ft_putchar_fd(*flag.str++, 1);
			flag.counter++;
		}
	}
	return (flag.counter);
}

int	ft_printf(const char *format, ...)
{
	int		x;
	va_list	params;

	va_start(params, format);
	x = ft_router(params, format);
	va_end(params);
	return (x);
}

/*
	printf("\nstr     = %3s\n", flag.str);
	printf("zero    = %3i\n", flag.zero);
	printf("minus   = %3i\n", flag.minus);
	printf("dot     = %3i\n", flag.dot);
	printf("type    = %3c\n", flag.type);
	printf("regular = %3i\n", flag.regular);
	printf("min     = %3i\n", flag.min);
	printf("counter = %3i\n", flag.counter);
	printf("noprint = %3i\n", flag.noprint);
	printf("hexa_l  = %3i\n", flag.hexa_length);
	printf("special = %3i\n", flag.special);
*/