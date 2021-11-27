/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xauffray <xauffray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 11:38:59 by xauffray          #+#    #+#             */
/*   Updated: 2021/04/05 13:39:56 by xauffray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_fill_str(char const *s, unsigned int start, size_t len,
	char *str)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	while (s[x])
	{
		if (x >= start && y < len)
			str[y++] = s[x];
		x++;
	}
	str[y] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (!s)
		return (0);
	if (len > (size_t)ft_strlen(s))
		len = (size_t)ft_strlen(s);
	if (start > ((unsigned)(ft_strlen(s))))
	{
		str = ft_calloc((size_t)(len), 1);
		if (!str)
			return (NULL);
		return (str);
	}
	str = (char *)malloc(len + 1);
	if (!str || !s)
		return (NULL);
	str = ft_fill_str(s, start, len, str);
	return (str);
}
