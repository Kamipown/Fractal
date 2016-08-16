#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdelobbe <pdelobbe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/06 15:17:46 by pdelobbe          #+#    #+#              #
#    Updated: 2016/02/15 15:16:17 by pdelobbe         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME =	fractol

FLG =	-Wall -Wextra -Werror

SRC =	main.c \
		init.c \
		hooks.c \
		hooks_mandelbrot.c \
		hooks_julia.c \
		hooks_mandelbar.c \
		draw.c \
		draw_mandelbrot.c \
		draw_julia.c \
		draw_mandelbar.c \
		colors.c

OBJ =	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	make -C minilibx_macos
	gcc -O3 $(FLG) -I libft/includes/ -c $(SRC)
	gcc -o $(NAME) $(OBJ) -L./libft/ -lft -L./minilibx_macos/ -lmlx -framework OpenGL -framework AppKit

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
