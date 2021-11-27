/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xauffray <xauffray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 11:38:59 by xauffray          #+#    #+#             */
/*   Updated: 2021/04/05 14:11:42 by xauffray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	len;
	int	x;

	x = 0;
	len = ft_strlen(str);
	if (c == 0)
		return ((char *)str + len);
	str += len - 1;
	while (x < len)
	{
		if (*(str - x) == (char)c)
			return ((char *)(str - x));
		x++;
	}
	return (NULL);
}
