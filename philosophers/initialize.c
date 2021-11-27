/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xauffray <xauffray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 10:56:53 by xauffray          #+#    #+#             */
/*   Updated: 2021/10/13 15:00:00 by xauffray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	intilalize_philo(t_room *r, int counter, char **argv, double start)
{
	double			time_mili;
	struct timeval	time;

	gettimeofday(&time, NULL);
	time_mili = time.tv_sec * 1000 + time.tv_usec / 1000 - start;
	r->philosophers = malloc(sizeof(t_ph) * counter);
	if (!r->philosophers)
		return ;
	while (counter)
	{
		r->philosophers[counter - 1].index = counter;
		r->philosophers[counter - 1].is_alive = 1;
		r->philosophers[counter - 1].has_fork = 0;
		r->philosophers[counter - 1].time_to_die = ft_atoi(argv[2]);
		r->philosophers[counter - 1].time_to_eat = ft_atoi(argv[3]);
		r->philosophers[counter - 1].time_to_sleep = ft_atoi(argv[4]);
		r->philosophers[counter - 1].last_meal = time_mili;
		r->philosophers[counter - 1].start = start;
		r->philosophers[counter - 1].room = r;
		r->philosophers[counter - 1].meals = 0;
		counter--;
	}
}

static void	initialize_room(t_room *r, char **argv, int *error)
{
	pthread_t		death;
	pthread_mutex_t	*forks;
	pthread_mutex_t	write;

	forks = malloc(sizeof(pthread_mutex_t) * (ft_atoi(argv[1]) + 1));
	if (!forks)
		return (there_is_an_error(error));
	death = NULL;
	r->go = 0;
	r->end = 0;
	r->death = death;
	r->forks = forks;
	r->num_of_ph = ft_atoi(argv[1]);
	pthread_mutex_init(&write, NULL);
	r->write = write;
	if (argv[5])
		r->stop = ft_atoi(argv[5]);
	else
		r->stop = -1;
}

static double	inititalize_time(void)
{
	double			start;
	struct timeval	time;

	gettimeofday(&time, NULL);
	start = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (start);
}

static void	create_thread_and_init_mutex(t_room *r, pthread_t *tphilo)
{
	int	x;

	x = r->num_of_ph;
	while (x--)
	{
		pthread_create(&tphilo[x], NULL, handler, &(r->philosophers[x]));
		pthread_mutex_init(&r->forks[x + 1], NULL);
	}
}

void	init(char **argv, int *error)
{
	t_room		r;
	pthread_t	*tphilo;
	int			x;

	tphilo = malloc(sizeof(pthread_t) * ft_atoi(argv[1]));
	if (!tphilo)
		return (there_is_an_error(error));
	initialize_room(&r, argv, error);
	if (*error)
		return (return_and_free(tphilo, &r, 1));
	intilalize_philo(&r, r.num_of_ph, argv, inititalize_time());
	if (!r.philosophers)
		return (return_and_free(tphilo, &r, 2));
	create_thread_and_init_mutex(&r, tphilo);
	pthread_create(&r.death, NULL, checker, &r);
	r.go = 1;
	x = r.num_of_ph;
	while (x--)
		pthread_join(tphilo[x], NULL);
	x = r.num_of_ph;
	while (x--)
		pthread_mutex_destroy(&r.forks[x + 1]);
	return_and_free(tphilo, &r, 3);
}
