# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acondor <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/11 19:45:00 by acondor           #+#    #+#              #
#    Updated: 2017/12/14 16:22:26 by acondor          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = ft_*.c
OWS = ft_*.o

all: $(NAME)

$(NAME):
	@gcc -c -Wall -Wextra -Werror $(SRC)
	@ar rc $(NAME) $(OWS)

clean:
	@rm -f $(OWS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
	@ar rc $(NAME) $(OWS)
