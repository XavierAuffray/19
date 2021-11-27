/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xauffray <xauffray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 12:08:48 by xauffray          #+#    #+#             */
/*   Updated: 2021/06/11 09:00:18 by xauffray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*select_number(char *str)
{
	int		x;

	x = 0;
	while (!ft_isnum(str[x]))
	{
		if (str[x] == '\e')
			return (0);
		x++;
	}
	x = 0;
	while (ft_iswhitespace(str[x]))
		x++;
	if (str[x] != '-' && str[x] != '+' && !ft_isnum(str[x]))
		return (0);
	return (str + x);
}

static int	inc_x(int x, const char *str)
{
	if (str[x] == '-' || str[x] == '+')
		x++;
	while (ft_isnum(str[x]))
		x++;
	return (x);
}

static long	fill_number(const char *str)
{
	size_t	x;
	long	y;
	long	number;

	y = 1;
	x = 0;
	x = inc_x(x, str);
	number = 0;
	while (x)
	{
		if (ft_isnum(str[x - 1]))
		{
			number += ((str[x - 1] - '0') * y);
			y *= 10;
		}
		x--;
	}
	return (number);
}

long	ft_atoi(const char *str)
{
	long	number;
	long	sign;

	sign = 1;
	if (!*str)
		return (0);
	str = select_number((char *)str);
	if (!str)
		return (0);
	if (*str == '-')
		sign = -1;
	number = fill_number(str);
	return ((number * sign));
}