/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xauffray <xauffray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 11:11:11 by xauffray          #+#    #+#             */
/*   Updated: 2021/04/26 11:11:12 by xauffray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_flag	put_0x(t_flag flag)
{
	ft_putstr_fd("0x", 1);
	flag.counter += 2;
	return (flag);
}

t_flag	put_0(t_flag flag)
{
	ft_putchar_fd('0', 1);
	flag.counter++;
	return (flag);
}

t_flag	put_space(t_flag flag)
{
	ft_putchar_fd(' ', 1);
	flag.counter++;
	return (flag);
}
