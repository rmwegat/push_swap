CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinc

NAME = push_swap
SRC_DIR = src

SRC_FILES = main.c \
	commands/pushes.c \
	commands/reverse_rotations.c \
	commands/rotations.c \
	commands/swaps.c \
	sorter/case_sort.c \
	sorter/case_sort_utils.c \
	sorter/case_sort_utils2.c \
	sorter/sort.c \
	stack_utils/init_stack.c \
	stack_utils/stack_utils.c

SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS = $(patsubst $(SRC_DIR)/%.c,objs/%.o,$(SRCS))

LIBFT_DIR = inc/libft
LIBFT = $(LIBFT_DIR)/libft/libft.a
PRINTF_DIR = $(LIBFT_DIR)/ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

all: $(NAME)

objs:
	@mkdir -p objs

objs/%.o: $(SRC_DIR)/%.c | objs
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	@echo "Compiling $(NAME)..."
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) -o $(NAME)
	@echo "Done."

$(LIBFT):
	@echo "Compiling libft..."
	@make bonus -C $(LIBFT_DIR)/libft > /dev/null
	@echo "Done."

$(PRINTF):
	@echo "Compiling printf..."
	@make -C $(PRINTF_DIR) > /dev/null
	@echo "Done."

clean:
	@echo "Cleaning..."
	@rm -f $(OBJS)
	@rm -rf objs
	@make -C $(LIBFT_DIR)/libft clean > /dev/null
	@make -C $(PRINTF_DIR) clean > /dev/null
	@echo "Done."

fclean: clean
	@rm -f $(NAME)
	@rm -rf objs
	@make -C $(LIBFT_DIR)/libft fclean > /dev/null
	@make -C $(PRINTF_DIR) fclean > /dev/null

re: fclean all

.PHONY: all clean fclean re
