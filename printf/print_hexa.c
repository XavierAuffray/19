/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xauffray <xauffray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 11:11:07 by xauffray          #+#    #+#             */
/*   Updated: 2021/04/26 11:11:08 by xauffray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	print_hexa(unsigned int i, char c)
{
	char	*hexa;

	if (c == 'x')
		hexa = "0123456789abcdef";
	else
		hexa = "0123456789ABCDEF";
	if (i >= 16)
	{
		print_hexa(i / 16, c);
		ft_putchar_fd(hexa[i % 16], 1);
	}
	else
		ft_putchar_fd(hexa[i], 1);
}
