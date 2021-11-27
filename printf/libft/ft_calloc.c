/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xauffray <xauffray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 11:38:59 by xauffray          #+#    #+#             */
/*   Updated: 2021/04/05 12:18:22 by xauffray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_calloc(size_t el_count, size_t el_size)
{
	void	*pointer;

	pointer = (void *)malloc(el_size * el_count);
	if (!pointer)
		return (NULL);
	ft_memset(pointer, 0, el_count * el_size);
	return (pointer);
}
