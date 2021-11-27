/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others_pointers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xauffray <xauffray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 11:10:54 by xauffray          #+#    #+#             */
/*   Updated: 2021/04/26 11:10:55 by xauffray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_flag	others_pointers(t_flag flag, void *current)
{
	flag = put_0x(flag);
	if (current)
	{
		print_address(*(unsigned long long *)&current);
		flag.counter += flag.hexa_length;
	}
	else if (!current && !flag.dot)
	{
		ft_putchar_fd('0', 1);
		flag.counter++;
	}
	return (flag);
}
