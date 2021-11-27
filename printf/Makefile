# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xauffray <xauffray@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/04 11:38:59 by xauffray          #+#    #+#              #
#    Updated: 2021/04/05 12:25:03 by xauffray         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc -c
LIBFT_PATH = ./libft/
LIBFTA = libft.a
CFLAGS = -Wall -Wextra -Werror
HEADER = -I ./
FILES = 	ft_printf.c 				\
			handle_c.c					\
			handle_i.c					\
			handle_p.c					\
			handle_pct.c				\
			handle_s.c					\
			handle_u.c					\
			handle_x.c					\
			handle_X.c					\
			handle_XX.c					\
			print_address.c				\
			print_hexa.c				\
			is_flag_zero.c				\
			is_flag_minus.c				\
			is_flag_dot.c				\
			is_flag_min.c				\
			is_regular.c				\
			uint_len.c					\
			ft_include.c				\
			ft_hexa_length.c			\
			only_positive.c 			\
			ft_putuint.c 				\
			int_len.c					\
			handle_regular_string.c 	\
			handle_min_u.c 				\
			inc_z_id_minus.c 			\
			inc_z_id_min.c 				\
			inc_z_x_minus.c 			\
			help_number3.c 				\
			puts.c 						\
			others_pointers.c 			\
			others_x.c 					\

OBJECTS = ${FILES:.c=.o}

all:		${NAME}

${NAME}: 	${OBJECTS}
			@make -C ${LIBFT_PATH}
			@cp ${LIBFT_PATH}${LIBFTA} ${NAME}
			@${CC} ${CFLAGS} ${FILES} ${HEADER}
			@ar rc ${NAME} ${OBJECTS}
			@ranlib ${NAME}
			@printf "\e[32m ________________________________________\n"
			@printf "|___ Libftprintf successfully created ___|\e[0m\n\n"

clean:
			@rm -f ${OBJECTS}
			@printf "\e[91m ___________________________\n"
			@printf "|___ All objects removed ___|\e[0m\n\n"


fclean:		clean
			@make fclean -C ${LIBFT_PATH}
			@rm -f ${NAME}
			@rm -f ${LIBFTA}
			@printf "\e[91m _____________________________\n"
			@printf "|___ ${NAME} removed ___|\e[0m\n\n"


re:			fclean
			make
