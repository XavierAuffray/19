/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xauffray <xauffray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 10:56:30 by xauffray          #+#    #+#             */
/*   Updated: 2021/10/14 09:17:51 by xauffray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	lock_forks(t_ph *philo)
{
	if (!philo->meals && philo->index % 2 == 1)
		usleep(2000);
	if (philo->index % 2 == 1)
	{
		pthread_mutex_lock(&philo->room->forks[philo->index]);
		if (philo->index == philo->room->num_of_ph)
			pthread_mutex_lock(&philo->room->forks[1]);
		else
			pthread_mutex_lock(&philo->room->forks[philo->index + 1]);
	}
	else
	{
		if (philo->index == philo->room->num_of_ph)
			pthread_mutex_lock(&philo->room->forks[1]);
		else
			pthread_mutex_lock(&philo->room->forks[philo->index + 1]);
		pthread_mutex_lock(&philo->room->forks[philo->index]);
	}
}

void	unlock_forks(t_ph *philo)
{
	if (philo->index % 2 == 1)
	{
		pthread_mutex_unlock(&philo->room->forks[philo->index]);
		if (philo->index == philo->room->num_of_ph)
			pthread_mutex_unlock(&philo->room->forks[1]);
		else
			pthread_mutex_unlock(&philo->room->forks[philo->index + 1]);
	}
	else
	{
		if (philo->index == philo->room->num_of_ph)
			pthread_mutex_unlock(&philo->room->forks[1]);
		else
			pthread_mutex_unlock(&philo->room->forks[philo->index + 1]);
		pthread_mutex_unlock(&philo->room->forks[philo->index]);
	}
}
