NAME = cubed

MLX = libmlx-Linux.a
MLX_DIR = minilibx-linux/

UTILS = utils/utils.a
UTILS_DIR = utils/

CC = cc
CFLAGS = -Wall -Werror -Wextra -lm -g 
LIBX_FLAGS = -Lminilibx-linux -lmlx -lXext -lX11 -Lutils

SRC = main.c \
	hooks.c \
	matrix_utils.c \
	close.c \
	draw.c \
	movements.c \
	3d_calculations.c \

all: $(NAME)

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

$(UTILS):
	$(MAKE) -C $(UTILS_DIR)

$(MLX):
	@$(MAKE) -C $(MLX_DIR)

$(NAME): $(MLX) $(PRINTF) $(UTILS)
	$(CC) $(CFLAGS) $(SRC) $(UTILS) $(LIBX_FLAGS) -o $(NAME)


clean:
	rm -f

fclean: clean
	rm -f $(NAME)
	
re: fclean $(NAME)

.PHONY: all clean fclean re
