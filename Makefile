CC = cc
CFLAGS = -Wall -Wextra -Werror
MAKE = make
NAME = pipex
FTPRINTF_DIR = ftprintf
FTPRINTF = $(FTPRINTF_DIR)/libftprintf.a
GNL_DIR = get_next_line
INCLUDE = include
SRC = src/pipex.c \
      src/utils.c \
      $(GNL_DIR)/get_next_line.c \
      $(GNL_DIR)/get_next_line_utils.c
OBJ = $(SRC:.c=.o)

all:	$(FTPRINTF) $(NAME)

$(FTPRINTF):
	$(MAKE) -C $(FTPRINTF_DIR)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(FTPRINTF) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I. -I$(INCLUDE) -I$(FTPRINTF_DIR) -I$(GNL_DIR) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(FTPRINTF_DIR) clean

fclean:	clean
	rm -f $(NAME)
	$(MAKE) -C $(FTPRINTF_DIR) fclean

re:	fclean all

.PHONY:	all clean fclean re
