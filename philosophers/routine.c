/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xauffray <xauffray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 10:57:14 by xauffray          #+#    #+#             */
/*   Updated: 2021/10/13 09:22:36 by xauffray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	go_to_eat(t_ph *philo)
{
	if (check_number_of_philo(philo))
		return ;
	lock_forks(philo);
	print_message(1, philo);
	unlock_forks(philo);
}

void	go_to_sleep(t_ph *philo)
{
	double			time_mili;
	struct timeval	time;

	gettimeofday(&time, NULL);
	time_mili = time.tv_sec * 1000 + time.tv_usec / 1000 - philo->start;
	print_message(2, philo);
}

void	go_to_think(t_ph *philo)
{
	double			time_mili;
	struct timeval	time;

	gettimeofday(&time, NULL);
	time_mili = time.tv_sec * 1000 + time.tv_usec / 1000 - philo->start;
	print_message(3, philo);
}
