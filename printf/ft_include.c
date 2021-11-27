/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_include.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xauffray <xauffray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 11:08:30 by xauffray          #+#    #+#             */
/*   Updated: 2021/04/26 11:08:31 by xauffray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_include(char *str, int c)
{
	while (*str)
	{
		if (*str == (char)c)
			return (1);
		str++;
	}
	return (0);
}
