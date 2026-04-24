CC := cc
CFLAGS := -Wall -Wextra -Werror
NAME := libftprintf.a
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS := ft_printf.c \
	buffer.c \
	checks.c \
	conversions.c \
	conversions_helpers.c \
	conversions_helpers_2.c \
	flags.c \
	flags_helpers.c \
	flags_helpers_2.c \
	utils.c \
	utils_2.c

OBJS := $(SRCS:.c=.o)

all:	$(LIBFT) $(NAME)

bonus:	$(LIBFT) $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJS)

%.o : %.c ft_printf.h
	$(CC) $(CFLAGS) -I. -I$(LIBFT_DIR) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re:	fclean all

.PHONY: all clean fclean re
