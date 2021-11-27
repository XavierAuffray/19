/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_number3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xauffray <xauffray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 11:09:46 by xauffray          #+#    #+#             */
/*   Updated: 2021/04/26 11:09:46 by xauffray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_flag	help_number3(t_flag flag, int x)
{
	int	z;

	z = ft_atoi(flag.str + 1);
	flag.minus = z;
	flag.str += x + 1;
	flag.type = *flag.str;
	return (flag);
}
