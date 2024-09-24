CC = cc
FLAGS = -Wall -Wextra -Werror

SRC = main.c parse_map.c

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
GET_NEXT_LINE = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

OBJ = $(SRC:.c=.o) $(GET_NEXT_LINE:.c=.o)

NAME = so_long

all: LIBFTMAKE $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) -L$(LIBFT_DIR) -lft 

LIBFTMAKE:
	make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJ)
	make -C $(LIBFT_DIR) clean

fclean: clean

re: fclean all

.PHONY: all clean fclean re