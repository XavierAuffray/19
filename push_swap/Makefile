NAME = push_swap
LIBFT_PATH = libft/
LIBFTA = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
FILES = push_swap.c 			\
		actions.c				\
		create_stacks.c 			\
		free_functions.c 			\
		bbsort.c 					\
		radix.c 					\
		errors.c 					\
		magic_trick.c 				\
		utils.c 					\

OBJECTS = ${FILES:.c=.o}

all: ${NAME}

${NAME}: 	${OBJECTS}
			@make -C ${LIBFT_PATH}
			@cp ${LIBFT_PATH}${LIBFTA} .
			@${CC} ${CFLAGS} ${FILES} ${LIBFTA} -o ${NAME}
			@printf "\e[32m ______________________________________\n"
			@printf "|___ Push_swap successfully created ___|\e[0m\n\n"

clean:
			@rm -f ${OBJECTS}
			@printf "\e[91m ___________________________\n"
			@printf "|___ All objects removed ___|\e[0m\n\n"

fclean:
			@make clean
			@make fclean -C ${LIBFT_PATH}
			@rm -f ${NAME}
			@rm -f ${LIBFTA}
			@printf "\e[91m __________________________\n"
			@printf "|___ executable removed ___|\e[0m\n\n"
			@printf "\e[91m _______________________\n"
			@printf "|___ ${LIBFTA} removed ___|\e[0m\n\n"

re:
			make fclean
			make