/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_regular_string.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xauffray <xauffray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 11:09:18 by xauffray          #+#    #+#             */
/*   Updated: 2021/04/26 11:09:19 by xauffray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_flag	handle_regular_string(t_flag flag, void *current)
{
	ft_putstr_fd((char *)current, 1);
	flag.counter += ft_strlen((char *)current);
	return (flag);
}
