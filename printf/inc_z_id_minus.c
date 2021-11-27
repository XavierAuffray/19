/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inc_z_id_minus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xauffray <xauffray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 11:09:54 by xauffray          #+#    #+#             */
/*   Updated: 2021/04/26 11:09:54 by xauffray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	inc_z_id_minus(t_flag flag, int len, int y)
{
	int	z;

	z = 0;
	if ((flag.zero > len - 1) && y < 0)
		z++;
	if (!flag.zero && flag.dot)
		z--;
	if (flag.dot && !flag.min && !flag.zero
		&& !flag.regular && y)
		z++;
	return (z);
}
