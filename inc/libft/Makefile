NAME = lib.a
CPP_FLAGS = -Wall -Wextra -Werror
CPP = c++

SRCS = # Add your C++ source files here if needed
OBJS = $(SRCS:.cpp=.o)

LIBFT_DIR = ./libft
PRINTF_DIR = ./ft_printf

LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a

all: $(LIBFT) $(PRINTF) $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) bonus > /dev/null

$(PRINTF):
	@$(MAKE) -C $(PRINTF_DIR) all > /dev/null

$(NAME): $(LIBFT) $(PRINTF)
	@if [ -s $(LIBFT) ] && [ -s $(PRINTF) ]; then \
		cp $(LIBFT) $(NAME); \
		ar rcs $(NAME) $(PRINTF); \
	else \
		echo "\033[1;31m ⚠️  [lib.a not created: one or more libraries are empty]\033[0m"; \
	fi

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean > /dev/null
	@$(MAKE) -C $(PRINTF_DIR) clean > /dev/null

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean > /dev/null
	@$(MAKE) -C $(PRINTF_DIR) fclean > /dev/null

re: fclean all

.SILENT: $(OBJS)

.PHONY: all clean fclean re
