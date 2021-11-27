/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uint_len.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xauffray <xauffray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 11:11:18 by xauffray          #+#    #+#             */
/*   Updated: 2021/04/26 11:11:18 by xauffray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	uint_len(unsigned int n)
{
	int	len;

	len = 1;
	while (n / 10 > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}
