# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mflorea <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/10 02:49:28 by mflorea           #+#    #+#              #
#    Updated: 2018/02/10 03:12:45 by mflorea          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

MLX = -lmlx -framework OpenGL -framework AppKit

SRC = read.c collor.c projection.c main.c display.c mlx_hook.c mlx.c

OBJ = $(SRC:.c=.o)

INC = includes/

all: $(NAME)

$(NAME):
		@make -C ./libft
		@gcc -Wall -Wextra -Werror -I $(INC) -c $(SRC)
		@gcc $(OBJ) -L libft/ -lft -o $(NAME) $(MLX)

clean:
		@make -C ./libft clean
		@/bin/rm -rf $(OBJ)

fclean: clean
		@make -C ./libft fclean
		@/bin/rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
