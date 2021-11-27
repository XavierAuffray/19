/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xauffray <xauffray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 11:38:59 by xauffray          #+#    #+#             */
/*   Updated: 2021/04/05 13:01:30 by xauffray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	x;
	size_t	y;

	x = ft_strlen(dest);
	y = ft_strlen(src);
	if (size == 0 || x > size)
		return (size + y);
	if (!src)
		return (x);
	y = 0;
	while (src[y] && (x + y < size - 1))
	{
		dest[x + y] = src[y];
		y++;
	}
	dest[x + y] = '\0';
	return (x + ft_strlen(src));
}
