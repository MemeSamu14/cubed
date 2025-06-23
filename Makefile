NAME = cubed

UTILS = utils/utils.a
UTILS_DIR = utils/

CC = cc
CFLAGS = -Wall -Werror -Wextra -g 

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
	close.c

all: $(NAME)

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

$(UTILS):
	$(MAKE) -C $(UTILS_DIR)

$(NAME): $(PRINTF) $(UTILS)
	$(CC) $(CFLAGS) $(SRC) $(UTILS) -o $(NAME)

clean:
	rm -f

fclean: clean
	rm -f $(NAME)
	
re: fclean $(NAME)

.PHONY: all clean fclean re
