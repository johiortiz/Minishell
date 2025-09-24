NAME = minishell

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I$(LIBFT_DIR)

RM = rm -f
LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a
LDFLAGS = -L$(LIBFT_DIR) -lft

SRCS = main.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	# --- MODIFICADO: Añadidas las flags de enlazado y readline ---
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LDFLAGS) -lreadline

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C $(LIBFT_DIR) clean
	$(RM) $(OBJS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re