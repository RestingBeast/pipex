CC = cc
CFLAGS = -Wall -Wextra -Werror
MAKE = make
NAME = pipex
BONUS = pipex
FTPRINTF_DIR = ftprintf
FTPRINTF = $(FTPRINTF_DIR)/libftprintf.a
GNL_DIR = get_next_line
INCLUDE = -Iinclude -I$(FTPRINTF_DIR) -I$(GNL_DIR)
SRC = src/pipex.c \
      src/utils.c \
      src/parser.c
OBJ = $(SRC:.c=.o)
SRC_BONUS = src/utils.c \
			src/parser.c \
			bonus/pipex_bonus.c \
			bonus/utils_bonus.c \
			$(GNL_DIR)/get_next_line.c \
      		$(GNL_DIR)/get_next_line_utils.c
OBJ_BONUS = $(SRC_BONUS:.c=.o)

all:	$(FTPRINTF) $(NAME)

bonus: $(FTPRINTF) .bonus

$(FTPRINTF):
	$(MAKE) -C $(FTPRINTF_DIR)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(FTPRINTF) -o $(NAME)

.bonus: $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(FTPRINTF) -o $(NAME)
	@touch .bonus

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJ_BONUS) .bonus
	$(MAKE) -C $(FTPRINTF_DIR) clean

fclean:	clean
	rm -f $(NAME)
	$(MAKE) -C $(FTPRINTF_DIR) fclean

re:	fclean all

re_bonus: fclean bonus

.PHONY:	all bonus clean fclean re re_bonus
