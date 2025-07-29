NAME = cubed

UTILS = utils/utils.a
UTILS_DIR = utils/

CC = cc
CFLAGS = -Wall -Werror -Wextra -lm -g -O3
LIBX_FLAGS = -Lminilibx-linux -lmlx -lXext -lX11 -Lutils

SRC = main.c \
	parsing/parsing.c \
	parsing/check_colors.c \
	parsing/check_info.c \
	parsing/check_map.c \
	parsing/check_map_2.c \
	parsing/check_map_3.c \
	parsing/check_textures.c \
	matrix_utils.c \
	close.c \
	exec/exec.c \
	exec/hooks.c \
	exec/hooks_2.c \
	exec/draw.c \
	exec/draw_utils.c \
	exec/draw_loop.c \
	exec/movements.c \
	exec/3d_calculations.c \
	exec/3d_calculations_utils.c \
	exec/exec_init_1.c \
	exec/exec_init_2.c

SRC_BNS = main.c \
	parsing/parsing.c \
	parsing/check_colors.c \
	parsing/check_info.c \
	parsing/check_map.c \
	parsing/check_map_2.c \
	parsing/check_map_3_bonus.c \
	parsing/check_textures.c \
	matrix_utils.c \
	close.c \
	exec/exec_bonus.c \
	exec/hooks.c \
	exec/hooks_2.c \
	exec/draw.c \
	exec/draw_utils.c \
	exec/draw_loop_bonus.c \
	exec/movements.c \
	exec/3d_calculations.c \
	exec/3d_calculations_utils.c \
	exec/exec_init_1.c \
	exec/exec_init_2.c

all: $(NAME)

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

$(UTILS):
	$(MAKE) -C $(UTILS_DIR)

$(NAME): $(MLX) $(PRINTF) $(UTILS)
	$(CC) $(CFLAGS) $(SRC) $(UTILS) $(LIBX_FLAGS) -g -o $(NAME)


mlx:
	git clone https://github.com/42Paris/minilibx-linux.git ./minilibx-linux
	make -C ./minilibx-linux

clean:
	rm -f

fclean: clean
	rm -f $(NAME)
	
re: fclean $(NAME)

bonus: $(MLX) $(PRINTF) $(UTILS)
	$(CC) $(CFLAGS) $(SRC_BNS) $(UTILS) $(LIBX_FLAGS) -g -o $(NAME)


.PHONY: all clean fclean re
