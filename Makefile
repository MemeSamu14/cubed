NAME = cubed

MLX = `libmlx-Linux.a
MLX_DIR = minilibx-linux/

UTILS = utils/utils.a
UTILS_DIR = utils/

CC = cc
CFLAGS = -Wall -Werror -Wextra -g 
LIBX_FLAGS = -Lminilibx-linux -lmlx -lXext -lX11 -Lutils

SRC = main.c \
	parsing/parsing.c \
	parsing/check_colors.c \
	parsing/check_info.c \
	parsing/check_map.c \
	parsing/check_map_2.c \
	parsing/check_map_3.c \
	parsing/check_textures.c \
	exec/exec.c \
	matrix_utils.c \
	close.c \
	hooks.c \
	graphic/color_bg.c \
	graphic/graphic.c \
	graphic/mini_map.c \
	graphic/create_images.c 

all: $(NAME)

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

$(UTILS):
	$(MAKE) -C $(UTILS_DIR)

$(MLX):
	@$(MAKE) -C $(MLX_DIR)

$(NAME): $(MLX) $(PRINTF) $(UTILS)
	$(CC) $(CFLAGS)  $(SRC) $(UTILS) $(LIBX_FLAGS) -g -o $(NAME)


clean:
	rm -f

fclean: clean
	rm -f $(NAME)
	
re: fclean $(NAME)

.PHONY: all clean fclean re
