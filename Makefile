CC = cc
CFLAGS = -Wall -Wextra -Werror
MAKE = make
NAME = pipex
FTPRINTF_DIR = ftprintf
FTPRINTF = $(FTPRINTF_DIR)/libftprintf.a
INCLUDE = include
SRC = src/pipex.c
OBJ = $(SRC:.c=.o)

all:	$(FTPRINTF) $(NAME)

$(FTPRINTF):
	$(MAKE) -C $(FTPRINTF_DIR)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(FTPRINTF) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I. -I$(INCLUDE) -I$(FTPRINTF_DIR) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(FTPRINTF_DIR) clean

fclean:	clean
	rm -f $(NAME)
	$(MAKE) -C $(FTPRINTF_DIR) fclean

re:	fclean all

.PHONY:	all clean fclean re
