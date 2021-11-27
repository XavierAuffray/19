/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_occurence.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xauffray <xauffray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 12:18:57 by xauffray          #+#    #+#             */
/*   Updated: 2021/04/05 12:19:05 by xauffray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_check_occurence(char *src, char *to_find)
{
	int	tf_len;
	int	x;

	tf_len = ft_strlen(to_find);
	x = -1;
	while (tf_len > ++x)
		if (src[x] != to_find[x])
			return (0);
	return (1);
}
