NAME = push_swap
FT_PRINTF = ./ft_printf/libftprintf.a
INC = inc/
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRCS = \
	push_swap.c \
	find_nodes.c \
	ft_split.c \
	init_a_to_b.c \
	init_b_to_a.c \
	start_stack_a.c \
	push.c \
	put_error_and_free.c \
	rev_rotate.c \
	rotate.c \
	sort_stacks.c \
	swap.c \
	utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(FT_PRINTF) -o $(NAME)

$(FT_PRINTF):
	@make -C ./ft_printf

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	@make clean -C ./ft_printf

fclean: clean
	$(RM) $(NAME)
	$(RM) $(FT_PRINTF)

re: fclean all

.PHONY: all clean fclean re
