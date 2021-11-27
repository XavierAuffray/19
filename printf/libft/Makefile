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

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
HEADER = ./
FILES = 		ft_strlen.c 		 			\
				ft_check_occurence.c  			\
				ft_isascii.c 		 			\
				ft_memcpy.c 		 			\
				ft_strdup.c 		 			\
				ft_strnstr.c 		 			\
				ft_atoi.c 		 				\
				ft_isdigit.c 		 			\
				ft_memmove.c 		 			\
				ft_strlcat.c 		 			\
				ft_strrchr.c 		 			\
				ft_bzero.c 		 				\
				ft_isprint.c 		 			\
				ft_memset.c 		 			\
				ft_strlcpy.c 		 			\
				ft_calloc.c 		 			\
				ft_substr.c 		 			\
				ft_isalnum.c 		 			\
				ft_memccpy.c 		 			\
				ft_strchr.c 		 			\
				ft_strncmp.c 		 			\
				ft_tolower.c 		 			\
				ft_isalpha.c 		 			\
				ft_memchr.c 		 			\
				ft_strcpy.c 		 			\
				ft_toupper.c 		 			\
				ft_iswhitespace.c 	 			\
				ft_isnum.c 		 				\
				ft_memcmp.c 		 			\
				ft_strjoin.c 		 			\
				ft_strtrim.c 		 			\
				ft_split.c 		 				\
				ft_itoa.c 		 				\
				ft_strmapi.c 					\
				ft_putchar_fd.c 				\
				ft_putendl_fd.c 				\
				ft_putstr_fd.c 					\
				ft_putnbr_fd.c 					\
				# ft_strstr.c 		 			\
				# ft_strncpy.c 		 			\
				# ft_strcat.c 		 			\

OBJECTS = ${FILES:.c=.o}

FILES_BONUS = 	ft_lstnew.c 			\
				ft_lstadd_front.c 		\
				ft_lstsize.c			\
				ft_lstlast.c			\
				ft_lstadd_back.c		\
				ft_lstdelone.c 			\
				ft_lstclear.c 			\
				ft_lstiter.c  			\
				ft_lstmap.c   			\

OBJECTS_BONUS = ${FILES_BONUS:.c=.o}

all:		${NAME}

${NAME}:	${OBJECTS}
			@${CC} ${CFLAGS} -c ${FILES} -I ${HEADER}
			@ar rc ${NAME} ${OBJECTS}
			@ranlib ${NAME}
			@printf "\e[32m __________________________________\e[0m \n"
			@printf "\e[32m|___ Libft successfully created ___|\e[0m\n\n"


bonus:		${OBJECTS} ${OBJECTS_BONUS} 
			@${CC} ${CFLAGS} -c ${FILES} ${FILES_BONUS} -I ${HEADER}
			@ar rc ${NAME} ${OBJECTS_BONUS}
			@ranlib ${NAME}
			@printf "\e[32m ________________________________________\e[0m\n"
			@printf "\e[32m|___ Libft bonus successfully created ___|\e[0m\n\n"


clean:
			@rm -f ${OBJECTS}
			@rm -f ${OBJECTS_BONUS}
			@printf "\e[91m ___________________________\e[0m\n"
			@printf "\e[91m|___ All objects removed ___|\e[0m\n\n"


fclean:		clean
			@rm -f ${NAME}
			@rm -f libft.so
			@printf "\e[91m _______________________\e[0m\n"
			@printf "\e[91m|___ ${NAME} removed ___|\e[0m\n\n"


so:			fclean
			@${CC} -fPIC -c ${CFLAGS} ${FILES} ${FILES_BONUS} -I ${HEADER}
			@${CC} -shared -o libft.so ${OBJECTS} ${OBJECTS_BONUS}
			@printf "\e[32m _____________________________________\e[0m\n"
			@printf "\e[32m|___ Libft.so successfully created ___|\e[0m\n\n"


re:			fclean
			make
