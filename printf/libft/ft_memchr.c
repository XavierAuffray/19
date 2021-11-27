/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xauffray <xauffray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 11:38:59 by xauffray          #+#    #+#             */
/*   Updated: 2021/04/05 12:21:46 by xauffray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memchr(void *src, int c, size_t n)
{
	while (n-- && *(char *)src != (char)c)
		src++;
	if (!(n + 1))
		return (NULL);
	return (src);
}
