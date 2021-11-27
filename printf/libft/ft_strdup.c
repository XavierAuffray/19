/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xauffray <xauffray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 11:38:59 by xauffray          #+#    #+#             */
/*   Updated: 2021/04/05 13:00:25 by xauffray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strdup(char *str)
{
	char	*copy;
	int		length;
	int		x;

	length = ft_strlen(str);
	copy = (char *)malloc(length + 1);
	if (!copy)
		return (NULL);
	x = -1;
	while (str[++x] != '\0')
		copy[x] = str[x];
	copy[x] = '\0';
	return (copy);
}
