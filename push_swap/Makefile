# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/12 13:06:33 by rwegat            #+#    #+#              #
#    Updated: 2024/01/12 13:13:36 by rwegat           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
BONUS_NAME	= checker
CC			= cc
CFLAGS		= -Wall -Werror -Wextra

CFILES		=	push_swap.c\
				pushes.c\
				reverse_rotations.c\
				rotations.c\
				split.c\
				split_utils.c\
				stack_utils.c\
				swaps.c\
				
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