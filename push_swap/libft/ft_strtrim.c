/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xauffray <xauffray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 11:38:59 by xauffray          #+#    #+#             */
/*   Updated: 2021/04/05 13:05:51 by xauffray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	int		size;

	if (!s1 || !set)
		return (0);
	while (*s1 && ft_strchr((char *)set, *s1))
		s1++;
	size = ft_strlen(s1);
	while (size && ft_strchr((char *)set, *(s1 + size)))
		size--;
	result = ft_substr((char *)s1, 0, size + 1);
	return (result);
}
