# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pacadis <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/08 15:33:43 by pacadis             #+#    #+#              #
#    Updated: 2017/05/15 14:03:22 by pacadis            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	=	libftprintf.a

INC 	=	includes/

SRC		=	ft_atoi.c ft_buffer.c ft_char_str.c ft_convertor.c ft_format.c\
			ft_int.c ft_join.c ft_long.c ft_percent.c ft_pointer.c\
			ft_printf.c ft_putnbr.c ft_read_flags_conv.c ft_wstring.c\
			ft_read_length.c ft_read_width_prec.c ft_uint.c ft_wchar.c\

OBJ		=	$(SRC:.c=.o)

all: $(NAME)

$(NAME): 
			@gcc -Wall -Wextra -Werror -I$(INC) -c $(SRC)
			@ar rc $(NAME) $(OBJ)
			@ranlib $(NAME)
	

clean:
		@/bin/rm -f $(OBJ)

fclean: clean
		@/bin/rm -f $(NAME)

re: fclean all
