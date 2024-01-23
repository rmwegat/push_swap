# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/12 13:06:33 by rwegat            #+#    #+#              #
#    Updated: 2024/01/22 16:50:13 by rwegat           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap.a
BONUS_NAME	= checker
CC			= cc
CFLAGS		= -Wall -Werror -Wextra

CFILES		=	push_swap/init_stack.c\
				push_swap/push_swap.c\
				push_swap/pushes.c\
				push_swap/reverse_rotations.c\
				push_swap/rotations.c\
				push_swap/sorting_logic.c\
				push_swap/split_utils.c\
				push_swap/split.c\
				push_swap/stack_utils_libft.c\
				push_swap/stack_utils_new.c\
				push_swap/swaps.c\
				
OFILES		= $(CFILES:.c=.o)

all: $(NAME)
$(NAME):$(OFILES)
	ar rcs $(NAME) $(OFILES)
clean:
	rm -f $(OFILES)
fclean: clean
	rm -f $(NAME)
re: fclean $(NAME)
.PHONY: all clean fclean re