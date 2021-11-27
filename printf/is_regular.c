/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_regular.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xauffray <xauffray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 11:10:18 by xauffray          #+#    #+#             */
/*   Updated: 2021/04/26 11:10:19 by xauffray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_flag	is_regular(t_flag flag)
{
	if (ft_strchr("cspdiuxX%", *flag.str))
	{
		flag.type = *flag.str;
		flag.regular = 1;
	}
	return (flag);
}
