COLOR_GREEN = \033[0;92m
COLOR_RED   = \033[0;31m
COLOR_BLUE  = \033[0;34m

COLOR_RED    = \033[0;91m
COLOR_GREEN  = \033[0;92m
COLOR_YELLOW = \033[0;93m
COLOR_PURPLE = \033[0;94m
COLOR_PINK   = \033[0;95m
COLOR_CYAN   = \033[0;96m
COLOR_RESET  = \033[0m

ARG    = 2 1 3 6 5 8

NAME        = push_swap
BONUS_NAME  = checker
CC          = cc
CFLAGS      = -Wall -Wextra -Werror #-g #-fsanitize=address
SRC_DIR     = src
BONUS_DIR   = bonus
INCLUDE_DIR = include

SRC_MAIN    = $(SRC_DIR)/main.c
PS_OBJ      = $(SRC_MAIN:.c=.o)

SRCS = $(SRC_DIR)/loader.c \
$(SRC_DIR)/parser.c $(SRC_DIR)/checks.c $(SRC_DIR)/sort.c \
$(SRC_DIR)/presort.c $(SRC_DIR)/id.c $(SRC_DIR)/ps_utls.c \
$(SRC_DIR)/cost_util1.c $(SRC_DIR)/move.c $(SRC_DIR)/target.c\
$(SRC_DIR)/stack_op1.c $(SRC_DIR)/stack_op2.c \
$(SRC_DIR)/stack_op3.c $(SRC_DIR)/lst_utls1.c \
$(SRC_DIR)/lst_utls2.c $(SRC_DIR)/lst_utls3.c
OBJS = $(SRCS:.c=.o)

SRC_BONUS = $(SRC_DIR)/bonus/checker_bonus.c
BONUS_OBJ = $(SRC_BONUS:.c=.o)

.SILENT:

all: $(NAME)

$(NAME): $(PS_OBJ) $(OBJS)
	cd libft && make
	cd ..
	$(CC) $(CFLAGS) $(PS_OBJ) $(OBJS) -o $(NAME) -L./libft -lft
	echo "$(COLOR_GREEN)COMPILATION SUCCESSFUL ✓$(COLOR_RESET)"

bonus: $(BONUS_OBJ) $(OBJS)
	cd libft && make
	cd ..
	$(CC) $(CFLAGS) $(BONUS_OBJ) $(OBJS) -o $(BONUS_NAME) -L./libft -lft
	echo "$(COLOR_GREEN)BONUS COMPILED SUCCESSFULLY ✓$(COLOR_RESET)"

clean:
	cd $(SRC_DIR)
	rm -f $(PS_OBJ)
	rm -f $(OBJS)
	cd $(SRC_DIR)/$(BONUS_DIR)
	rm -f $(BONUS_OBJ)
	cd libft && make clean

fclean: clean
	rm -f $(NAME)
	rm -f $(BONUS_NAME)
	cd libft && make fclean

re: fclean $(NAME)

t: all
	./$(NAME) $(ARG)

ret: re t

.PHONY: bonus