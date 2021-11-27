/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_length.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xauffray <xauffray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 11:08:24 by xauffray          #+#    #+#             */
/*   Updated: 2021/04/26 11:08:24 by xauffray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_flag	ft_hexa_length(t_flag flag, unsigned long long i)
{
	if (i >= 16)
	{
		flag.hexa_length++;
		return (ft_hexa_length(flag, i / 16));
	}
	else
	{
		flag.hexa_length++;
		return (flag);
	}
}
