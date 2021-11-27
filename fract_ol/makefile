NAME= fractol
CC= gcc -Wall -Wextra -Werror
FILES= 	fractol.c		\
		scroll.c 		\
		mandelbrot.c 	\
		arrows.c 		\
		zoom.c 			\
		precision.c 	\
		utils.c 		\
		julia.c 		\
		# shapes.c				

${ALL}: $(NAME)

$(NAME):
	@$(CC) $(FILES) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@printf "\e[32m ____________________________________\e[0m \n"
	@printf "\e[32m|___ fractol successfully created ___|\e[0m\n\n"

clean:
	@rm -f $(NAME)
	@printf "\e[91m _______________________\n"
	@printf "|___ fractol removed ___|\e[0m\n\n"

fclean:
	@rm -f $(NAME)
	@printf "\e[91m _______________________\n"
	@printf "|___ fractol removed ___|\e[0m\n\n"

re:
	@make fclean
	@make