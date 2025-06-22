NAME = cubed

UTILS = utils/utils.a
UTILS_DIR = utils/

CC = cc
CFLAGS = -Wall -Werror -Wextra -g 

SRC = main.c \
	parsing/parsing.c \
	exec/exec.c \
	matrix_utils.c

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
