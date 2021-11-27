/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xauffray <xauffray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 10:57:06 by xauffray          #+#    #+#             */
/*   Updated: 2021/10/14 09:38:23 by xauffray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	message_eat(t_ph *philo)
{
	double			time_mili;
	struct timeval	time;

	pthread_mutex_lock(&philo->room->write);
	gettimeofday(&time, NULL);
	time_mili = time.tv_sec * 1000 + time.tv_usec / 1000 - philo->start;
	if (!philo->room->end)
	{
		printf("%.0f %d has taken a fork\n", time_mili, philo->index);
		printf("%.0f %d has taken a fork\n", time_mili, philo->index);
		printf("%.0f %d is eating\n", time_mili, philo->index);
	}
	pthread_mutex_unlock(&philo->room->write);
	philo->last_meal = time_mili;
	my_usleep(philo->time_to_eat, philo);
	philo->meals += 1;
}

static void	message_sleep(t_ph *philo)
{
	double			time_mili;
	struct timeval	time;

	pthread_mutex_lock(&philo->room->write);
	gettimeofday(&time, NULL);
	time_mili = time.tv_sec * 1000 + time.tv_usec / 1000 - philo->start;
	if (!philo->room->end)
		printf("%.0f %d is sleeping\n", time_mili, philo->index);
	pthread_mutex_unlock(&philo->room->write);
	my_usleep(philo->time_to_sleep, philo);
}

static void	message_think(t_ph *philo)
{
	double			time_mili;
	struct timeval	time;

	pthread_mutex_lock(&philo->room->write);
	gettimeofday(&time, NULL);
	time_mili = time.tv_sec * 1000 + time.tv_usec / 1000 - philo->start;
	if (!philo->room->end)
		printf("%.0f %d is thinking\n", time_mili, philo->index);
	pthread_mutex_unlock(&philo->room->write);
}

void	print_message(int ref, t_ph *philo)
{
	if (ref == 1)
		message_eat(philo);
	else if (ref == 2)
		message_sleep(philo);
	else if (ref == 3 && !check_dead(philo))
		message_think(philo);
}
