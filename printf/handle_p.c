/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xauffray <xauffray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 11:09:08 by xauffray          #+#    #+#             */
/*   Updated: 2021/04/26 11:09:09 by xauffray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static t_flag	handle_regular(t_flag flag, void *current)
{
	if (!flag.noprint && !flag.zero && !flag.dot && !flag.minus)
	{
		flag = put_0x(flag);
		if (current)
		{
			print_address(*(unsigned long long *)&current);
			flag.counter += flag.hexa_length;
		}
		else
			flag = put_0(flag);
	}
	return (flag);
}

static t_flag	handle_zero(t_flag flag, void *current)
{
	int					x;
	unsigned long long	y;
	int					z;

	x = 0;
	z = 0;
	y = *(unsigned long long *)&current;
	if (!flag.min)
		flag = put_0x(flag);
	if (!flag.dot)
		z += 2;
	while (flag.zero - x++ - flag.hexa_length > z)
		flag = put_0(flag);
	if ((flag.min || flag.dot) && current)
	{
		print_address(y);
		flag.counter += flag.hexa_length;
	}
	return (flag);
}

static t_flag	handle_minus(t_flag flag, void *current)
{
	int					x;
	unsigned long long	y;

	x = 0;
	y = *(unsigned long long *)&current;
	if (!flag.min && !flag.zero)
	{
		flag = put_0x(flag);
		if (!current && !flag.dot)
		{
			print_address(y);
			flag.counter += 1;
			x++;
		}
		else if (current)
		{
			print_address(y);
			flag.counter += flag.hexa_length;
		}
	}
	while (flag.minus - flag.hexa_length
		- only_positive(flag.zero - flag.hexa_length) - x++ > 2)
		flag = put_space(flag);
	return (flag);
}

static t_flag	handle_min(t_flag flag, void *current)
{
	int					x;
	unsigned long long	y;
	int					z;

	x = 0;
	y = *(unsigned long long *)&current;
	z = 2;
	if (!current && !flag.dot)
		z++;
	while (flag.min - x++ - flag.hexa_length
		- only_positive(flag.zero - flag.hexa_length) > z)
		flag = put_space(flag);
	flag = put_0x(flag);
	if (current && !flag.zero)
	{
		print_address(y);
		flag.counter += flag.hexa_length;
	}
	else if (!current && !flag.dot)
		flag = put_0(flag);
	return (flag);
}

t_flag	handle_p(t_flag flag, va_list params)
{
	void	*current;

	if (flag.type == 'p')
	{
		current = va_arg(params, unsigned long long *);
		flag = ft_hexa_length(flag, *(unsigned long long *)&current);
		if (!current)
			flag.hexa_length = 0;
		if (flag.regular)
			flag = handle_regular(flag, current);
		if (flag.min)
			flag = handle_min(flag, current);
		if (flag.zero)
			flag = handle_zero(flag, current);
		if (flag.minus)
			flag = handle_minus(flag, current);
		if ((flag.dot && !flag.min && !flag.zero && !flag.minus)
			|| (flag.special && !flag.zero && !flag.minus
				&& !flag.dot && !flag.min))
			flag = others_pointers(flag, current);
	}
	return (flag);
}
