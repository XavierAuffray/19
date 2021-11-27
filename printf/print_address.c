/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_address.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xauffray <xauffray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 11:11:03 by xauffray          #+#    #+#             */
/*   Updated: 2021/04/26 11:11:04 by xauffray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	print_address(unsigned long long i)
{
	char	*hexa;

	hexa = "0123456789abcdef";
	if (i >= 16)
	{
		print_address(i / 16);
		ft_putchar_fd(hexa[i % 16], 1);
	}
	else
		ft_putchar_fd(hexa[i], 1);
}
