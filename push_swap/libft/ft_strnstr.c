/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xauffray <xauffray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 11:38:59 by xauffray          #+#    #+#             */
/*   Updated: 2021/04/05 13:03:36 by xauffray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *src, const char *to_find, size_t x)
{
	if (!*to_find || to_find == NULL)
		return (src);
	if (!x)
		return (NULL);
	x -= (size_t)(ft_strlen(to_find));
	while (*src)
	{
		if (ft_check_occurence(src++, (char *)to_find))
			return (--src);
		if (!x--)
			return (NULL);
	}
	return (NULL);
}
