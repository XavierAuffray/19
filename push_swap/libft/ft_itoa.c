/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xauffray <xauffray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 11:38:59 by xauffray          #+#    #+#             */
/*   Updated: 2021/04/05 13:19:28 by xauffray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	int_len(long n)
{
	int	len;

	len = 1;
	while (n / 10 > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*num_equal_zero(void)
{
	char	*result;

	result = (char *)malloc(2);
	if (!result)
		return (NULL);
	result[0] = '0';
	result[1] = '\0';
	return (result);
}

static int	ft_set_sign(long num)
{
	int	sign;

	if (num < 0)
		sign = 1;
	else
		sign = 0;
	return (sign);
}

static char	*ft_fill_result(long num, char *result, int len, int sign)
{
	int	x;

	result[len] = '\0';
	x = 0;
	while (num > 0)
	{
		result[len - 1 - x++] = (num % 10) + '0';
		num /= 10;
	}
	if (sign == 1)
		result[0] = '-';
	return (result);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		len;
	int		sign;
	long	num;

	num = (long)(n);
	if (num == 0)
		return (num_equal_zero());
	sign = ft_set_sign(num);
	if (sign == 1)
		num = -num;
	len = int_len(num) + sign;
	result = (char *)malloc(len + 1);
	if (!result)
		return (NULL);
	result = ft_fill_result(num, result, len, sign);
	return (result);
}
