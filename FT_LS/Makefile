NAME = ft_ls

SRC = main.c handle_print.c handling_list.c printing_func.c sort_list.c \
	  basic_func.c list_sum_handler.c hand_perms.c hand_print.c get_digits.c
OBJ = $(SRC:.c=.o)

INCL = ft_ls.h

all: $(NAME)

$(NAME):
	@make -C libft
	@gcc -Wall -Werror $(INCL) -c $(SRC)
	@gcc $(OBJ) ./libft/libft.a -o $(NAME)

clean:
	@make -C ./libft clean
	@rm -rf 
