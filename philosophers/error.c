/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xauffray <xauffray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:51:58 by xauffray          #+#    #+#             */
/*   Updated: 2021/10/13 14:52:11 by xauffray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	an_error_occured(int argc, char **argv)
{
	int	x;

	x = 0;
	if (argc < 5 || argc > 6)
	{
		printf("Please provide 4 or 5 arguments\n");
		return (1);
	}
	while (argc > 1)
	{
		while (argv[argc - 1][x])
		{
			if (!ft_isnum(argv[argc - 1][x]) || ft_atoi(argv[argc - 1]) <= 0)
			{
				printf("'%s' is an invalid argument\n", argv[argc - 1]);
				return (1);
			}
			x++;
		}
		x = 0;
		argc--;
	}
	return (0);
}

void	there_is_an_error(int *error)
{
	*error = 1;
	return ;
}
