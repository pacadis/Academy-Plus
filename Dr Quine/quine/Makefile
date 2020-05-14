# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pacadis <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/16 11:04:33 by pacadis           #+#    #+#              #
#    Updated: 2017/12/18 18:52:33 by pacadis          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = Colleen
NAME2 = Grace
NAME3 = Sully

SRC1 = ./mandatory_part/Colleen.c
SRC2 = ./mandatory_part/Grace.c
SRC3 = ./mandatory_part/Sully.c

OBJ1 = Colleen.o
OBJ2 = Grace.o
OBJ3 = Sully.o

FLAGS = -Wall -Wextra -Werror

all: $(NAME1) $(NAME2) $(NAME3)

$(NAME1): $(SRC1)
	gcc $(FLAGS) -c $(SRC1)
	gcc -o $(NAME1) $(OBJ1)
	
$(NAME2): $(SRC2)
	gcc $(FLAGS) -c $(SRC2)
	gcc -o $(NAME2) $(OBJ2)

$(NAME3): $(SRC3)
	gcc $(FLAGS) -c $(SRC3)
	gcc -o $(NAME3) $(OBJ3)

clean:
	rm -rf $(OBJ1)
	rm -rf $(OBJ2)
	rm -rf $(OBJ3)

fclean: clean
	rm -rf $(NAME1)
	rm -rf $(NAME2)
	rm -rf $(NAME3)

re: fclean all
