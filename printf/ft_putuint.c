/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xauffray <xauffray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 11:08:43 by xauffray          #+#    #+#             */
/*   Updated: 2021/04/26 11:08:43 by xauffray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putuint(unsigned int n)
{
	if (n < 10)
		ft_putchar_fd(n + '0', 1);
	else
	{
		ft_putuint(n / 10);
		ft_putchar_fd(n % 10 + '0', 1);
	}
}
