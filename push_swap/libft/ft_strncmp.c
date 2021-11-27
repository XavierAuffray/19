/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xauffray <xauffray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 11:38:59 by xauffray          #+#    #+#             */
/*   Updated: 2021/04/05 13:02:46 by xauffray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t x)
{
	if (x == 0 || (!s1 && !s2))
		return (0);
	while (x != 1 && *s1 && *s1 == *s2)
	{
		s1++;
		s2++;
		x--;
	}
	if (*s1 == *s2)
		return (0);
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
