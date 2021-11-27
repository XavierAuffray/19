/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inc_z_x_minus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xauffray <xauffray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 11:09:57 by xauffray          #+#    #+#             */
/*   Updated: 2021/04/26 11:09:57 by xauffray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	inc_z_x_minus(t_flag flag, unsigned int y)
{
	int	z;

	z = 0;
	if (flag.zero)
		z++;
	if (flag.regular || (flag.noprint && y && flag.special))
		z++;
	if (!flag.zero && flag.dot)
		z--;
	if (flag.regular || flag.zero)
		z--;
	if (flag.dot && !flag.special && !flag.zero && y)
		z++;
	if (!flag.zero && !flag.regular && !flag.min
		&& !flag.noprint && flag.special && y)
		z++;
	if (flag.special && !flag.dot && !flag.regular
		&& !flag.min && !flag.noprint)
		z--;
	if (flag.special && !flag.zero && !flag.dot
		&& !flag.regular && !flag.noprint && !y)
		z++;
	return (z);
}
