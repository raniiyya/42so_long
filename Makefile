CC = cc
FLAGS = -Wall -Wextra -Werror

SRC = main.c parse_map.c utils.c $(VALIDATE_MAP) $(VISUAL)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
GET_NEXT_LINE = get_next_line/get_next_line.c
VALIDATE_MAP = validate_map/validate_map.c \
validate_map/validate_border.c \
validate_map/validate_chars.c \
validate_map/validate_path.c \
validate_map/validate_rect.c

VISUAL = visual/init_game.c \
visual/fill_textures.c \
visual/map_height.c \
visual/map_width.c \
visual/actions.c

OBJ = $(SRC:.c=.o) $(GET_NEXT_LINE:.c=.o)

NAME = so_long

all: LIBFTMAKE $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) -L$(LIBFT_DIR) -Lminilibx-linux -lft -lmlx -lXext -lX11

LIBFTMAKE:
	make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJ)
	make -C $(LIBFT_DIR) clean

fclean: clean

re: fclean all

.PHONY: all clean fclean re