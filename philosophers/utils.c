/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xauffray <xauffray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 10:57:18 by xauffray          #+#    #+#             */
/*   Updated: 2021/10/13 15:06:28 by xauffray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	my_usleep(double time_to_wait, t_ph *philo)
{
	double			start;
	struct timeval	time;

	gettimeofday(&time, NULL);
	start = time.tv_sec * 1000 + time.tv_usec / 1000;
	while (1)
	{
		gettimeofday(&time, NULL);
		if (time.tv_sec * 1000 + time.tv_usec / 1000 - start >= time_to_wait)
			return ;
		if (philo->room->end)
			return ;
		usleep(500);
	}
}

int	check_number_of_philo(t_ph *philo)
{
	if (philo->room->num_of_ph <= 1)
	{
		while (1)
		{
			if (!philo->is_alive)
			{
				philo->room->end = 1;
				return (1);
			}
		}
	}
	return (0);
}

int	check_dead(t_ph *philo)
{
	if (philo->room->end || !philo->is_alive)
		return (1);
	return (0);
}

void	return_and_free(pthread_t *tphilo, t_room *r, int nb)
{
	if (nb == 1)
		free(tphilo);
	if (nb == 2)
	{
		free(tphilo);
		free(r->forks);
	}
	if (nb == 3)
	{
		free(tphilo);
		free(r->forks);
		free(r->philosophers);
		pthread_mutex_destroy(&r->write);
	}
}
