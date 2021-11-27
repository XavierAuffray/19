NAME = minitalk
CC = gcc
CFLAGS = -Wall -Wextra -Werror
HEADER = ./
FILES_SERVER = 	server.c 		 			\
				ft_atoi.c 					\
				ft_isnum.c 					\
				ft_iswhitespace.c 			\
				ft_putchar.c

FILES_CLIENT = 	client.c 		 			\
				ft_isnum.c 					\
				ft_iswhitespace.c 			\
				ft_atoi.c 					\
				ft_putchar.c

OBJECTS_SERVER = ${FILES_SERVER:.c=.o}

OBJECTS_CLIENT = ${FILES_CLIENT:.c=.o}

all:		${NAME}

${NAME}:	${OBJECTS_SERVER} ${OBJECTS_CLIENT} 
			@${CC} ${CFLAGS} ${FILES_SERVER} -I ${HEADER} -o server
			@printf "\e[32m __________________________________\e[0m \n"
			@printf "\e[32m|___ server successfully created ___|\e[0m\n\n"
			@${CC} ${CFLAGS} ${FILES_CLIENT} -I ${HEADER} -o client
			@printf "\e[32m __________________________________\e[0m \n"
			@printf "\e[32m|___ client successfully created ___|\e[0m\n\n"

clean:
			@rm -f ${OBJECTS_SERVER}
			@rm -f ${OBJECTS_CLIENT}
			@printf "\e[91m ___________________________\e[0m\n"
			@printf "\e[91m|___ All objects removed ___|\e[0m\n\n"


fclean:		clean
			@rm -f client
			@printf "\e[91m _______________________\e[0m\n"
			@printf "\e[91m|___ client removed ___|\e[0m\n\n"
			@rm -f server
			@printf "\e[91m _______________________\e[0m\n"
			@printf "\e[91m|___ server removed ___|\e[0m\n\n"

re:			fclean
			make
