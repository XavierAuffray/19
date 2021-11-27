/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xauffray <xauffray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 11:10:27 by xauffray          #+#    #+#             */
/*   Updated: 2021/04/26 11:10:27 by xauffray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H

# define LIBFTPRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft.h"

typedef struct s_flag
{
	char	*str;
	int		zero;
	int		minus;
	int		dot;
	int		counter;
	int		type;
	int		regular;
	int		min;
	int		hexa_length;
	int		noprint;
	int		special;
}	t_flag;

int			ft_printf(const char *format, ...);
int			router(char *str, va_list params);
int			ft_include(char *str, int c);
int			int_len(long n);
int			uint_len(unsigned int n);
int			ull_len(unsigned long long n);
int			ft_latoi(const char *str, int x);
int			inc_z_id_minus(t_flag flag, int len, int y);
int			inc_z_id_min(t_flag flag, int len, int y);
int			inc_z_x_minus(t_flag flag, unsigned int y);
int			only_positive(int x);
void		ft_putuint(unsigned int n);
void		print_address(unsigned long long i);
void		print_hexa(unsigned int i, char c);
t_flag		ft_hexa_length(t_flag flag, unsigned long long i);
t_flag		handle_c(t_flag flag, va_list params);
t_flag		handle_i(t_flag flag, va_list params);
t_flag		handle_p(t_flag flag, va_list params);
t_flag		handle_pct(t_flag flag);
t_flag		handle_s(t_flag flag, va_list params);
t_flag		handle_u(t_flag flag, va_list params);
t_flag		handle_x(t_flag flag, va_list params);
t_flag		handle_X(t_flag flag, va_list params);
t_flag		is_flag_zero(t_flag flag, va_list params);
t_flag		is_flag_minus(t_flag flag, va_list params);
t_flag		is_flag_dot(t_flag flag, va_list params);
t_flag		is_flag_min(t_flag flag, va_list params);
t_flag		is_regular(t_flag flag);
t_flag		handle_regular_string(t_flag flag, void *current);
t_flag		handle_min_u(t_flag flag, void *current);
t_flag		help_number3(t_flag flag, int x);
t_flag		put_0x(t_flag flag);
t_flag		put_0(t_flag flag);
t_flag		put_space(t_flag flag);
t_flag		others_pointers(t_flag flag, void *current);
t_flag		others_x(t_flag flag, void *current);
t_flag		others_xx(t_flag flag, void *current);

#endif
