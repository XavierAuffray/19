/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xauffray <xauffray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 10:28:56 by xauffray          #+#    #+#             */
/*   Updated: 2021/10/13 14:55:43 by xauffray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_ph
{
	int				index;
	int				is_alive;
	int				has_fork;
	double			time_to_die;
	double			time_to_eat;
	double			time_to_sleep;
	double			last_meal;
	double			start;
	int				meals;
	struct s_room	*room;
}				t_ph;

typedef struct s_room
{
	int				num_of_ph;
	t_ph			*philosophers;
	pthread_mutex_t	*forks;
	int				go;
	int				end;
	pthread_t		death;
	pthread_mutex_t	write;
	int				stop;
}				t_room;

int		ft_atoi(const char *str);
int		ft_isnum(char c);
int		ft_iswhitespace(char c);
void	my_usleep(double time_to_wait, t_ph *philo);
int		check_number_of_philo(t_ph *philo);
int		check_dead(t_ph *philo);
void	print_message(int ref, t_ph *philo);
void	lock_forks(t_ph *philo);
void	unlock_forks(t_ph *philo);
void	go_to_eat(t_ph *philo);
void	go_to_sleep(t_ph *philo);
void	go_to_think(t_ph *philo);
void	*handler(void *arg);
void	init(char **argv, int *error);
void	*checker(void *arg);
int		an_error_occured(int argc, char **argv);
void	there_is_an_error(int *error);
void	return_and_free(pthread_t *tphilo, t_room *r, int nb);

#endif