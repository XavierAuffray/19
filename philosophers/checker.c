/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xauffray <xauffray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 10:56:40 by xauffray          #+#    #+#             */
/*   Updated: 2021/10/14 10:13:28 by xauffray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*action(int x, t_room *r)
{
	double			time_mili;
	struct timeval	time;

	gettimeofday(&time, NULL);
	time_mili = time.tv_sec * 1000 + time.tv_usec / 1000
		- r->philosophers[x].start;
	pthread_mutex_lock(&r->write);
	r->philosophers[x].is_alive = 0;
	r->end = 1;
	printf("%.0f %d died\n", time_mili, r->philosophers[x].index);
	pthread_mutex_unlock(&r->write);
	return (0);
}

static int	everyone_is_full(t_room *r)
{
	int	x;

	x = 0;
	while (x < r->num_of_ph)
	{
		if (r->philosophers[x].meals < r->stop)
			return (0);
		x++;
	}
	r->end = 1;
	return (1);
}

void	*checker(void *arg)
{
	t_room			*r;
	int				x;
	double			time_mili;
	struct timeval	time;

	r = (t_room *)arg;
	x = 0;
	while (1)
	{
		if (r->stop != -1 && everyone_is_full(r))
			return (0);
		while (x < r->num_of_ph)
		{
			gettimeofday(&time, NULL);
			time_mili = time.tv_sec * 1000 + time.tv_usec / 1000
				- r->philosophers[x].start;
			if (time_mili - r->philosophers[x].last_meal
				> r->philosophers[x].time_to_die)
				return (action(x, r));
			x++;
		}
		x = 0;
	}
	return (0);
}
