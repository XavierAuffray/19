/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xauffray <xauffray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 11:38:59 by xauffray          #+#    #+#             */
/*   Updated: 2021/04/05 13:02:13 by xauffray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	x;
	char			*result;

	if (!s || !f)
		return (0);
	x = 0;
	result = (char *)malloc(ft_strlen(s) + 1);
	if (!result)
		return (NULL);
	while (*s)
	{
		result[x] = (*f)(x, *s++);
		x++;
	}
	result[x] = '\0';
	return (result);
}
