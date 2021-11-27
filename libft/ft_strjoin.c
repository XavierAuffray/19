/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xauffray <xauffray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 11:38:59 by xauffray          #+#    #+#             */
/*   Updated: 2021/04/05 13:00:45 by xauffray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		size;

	if (!s1 || !s2)
		return (0);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	result = (char *)malloc(size);
	if (!result)
		return (NULL);
	ft_strcpy(result, (char *)s1);
	ft_strlcat(result, (char *)s2, size);
	return (result);
}
