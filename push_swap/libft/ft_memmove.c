/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xauffray <xauffray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 11:38:59 by xauffray          #+#    #+#             */
/*   Updated: 2021/04/05 12:39:49 by xauffray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	x;

	x = 0;
	if (!src && !dest)
		return (dest);
	if (src == dest)
		return (dest);
	if (dest > src)
		while (n--)
			*(char *)(dest + n) = *(char *)(src + n);
	else
	{
		while (x < n)
		{
			*(char *)(dest + x) = *(char *)(src + x);
			x++;
		}
	}
	return (dest);
}
