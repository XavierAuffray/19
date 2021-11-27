/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inc_z_id_min.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xauffray <xauffray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 11:09:49 by xauffray          #+#    #+#             */
/*   Updated: 2021/04/26 11:09:50 by xauffray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	inc_z_id_min(t_flag flag, int len, int y)
{
	int	z;

	z = 0;
	if (flag.zero > len - 1 && y < 0)
		z++;
	if (y == 0 && flag.dot)
		z--;
	if (flag.zero && y == 0)
		z++;
	return (z);
}
