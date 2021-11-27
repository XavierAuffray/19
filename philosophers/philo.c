/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xauffray <xauffray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 10:29:00 by xauffray          #+#    #+#             */
/*   Updated: 2021/10/13 15:12:11 by xauffray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*handler(void *arg)
{
	t_ph			*philo;

	philo = (t_ph *)arg;
	while (!philo->room->go)
		;
	while (1)
	{
		go_to_think(philo);
		go_to_eat(philo);
		go_to_sleep(philo);
		if (check_dead(philo))
			break ;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	error;

	error = 0;
	if (an_error_occured(argc, argv))
		return (0);
	init(argv, &error);
	return (0);
}
