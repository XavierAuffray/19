# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xauffray <xauffray@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/12 10:56:59 by xauffray          #+#    #+#              #
#    Updated: 2021/10/12 13:39:29 by xauffray         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = gcc
CFLAGS = -Wall -Wextra -Werror
FILES = 	ft_atoi.c			\
			ft_isnum.c			\
			philo.c 			\
			ft_iswhitespace.c 	\
			utils.c 			\
			routine.c 			\
			messages.c 			\
			forks.c 			\
			checker.c 			\
			initialize.c 		\
			error.c 			\
				
OBJECTS = ${FILES:.c=.o}

all:		${NAME}

${NAME}:	${OBJECTS}
			@${CC} ${CFLAGS} ${FILES} -o ${NAME}
			@printf "\e[32m __________________________________\e[0m \n"
			@printf "\e[32m|___ Philo successfully created ___|\e[0m\n\n"


bonus:		${OBJECTS} ${OBJECTS_BONUS}
			@${CC} ${CFLAGS} -c ${FILES} ${FILES_BONUS} -I ${HEADER}
			@ar rc ${NAME} ${OBJECTS_BONUS}
			@ranlib ${NAME}
			@printf "\e[32m ________________________________________\e[0m\n"
			@printf "\e[32m|___ Philo bonus successfully created ___|\e[0m\n\n"


clean:
			@rm -f ${OBJECTS}
			@rm -f ${OBJECTS_BONUS}
			@printf "\e[91m ___________________________\e[0m\n"
			@printf "\e[91m|___ All objects removed ___|\e[0m\n\n"


fclean:		clean
			@rm -f ${NAME}
			@printf "\e[91m _______________________\e[0m\n"
			@printf "\e[91m|___ ${NAME} removed ___|\e[0m\n\n"

re:			fclean
			make