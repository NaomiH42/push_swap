# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehasalu <ehasalu@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/13 16:54:08 by ehasalu           #+#    #+#              #
#    Updated: 2023/02/22 16:04:27 by ehasalu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	push_swap
SRCS =	main.c push.c reverse_rotate.c rotate.c swap.c under_five.c utility_stuff.c cases.c
LIBFT_F = ./libft/
LIBFT_NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(LIBFT_NAME):
	@make -C $(LIBFT_F)

$(NAME): $(LIBFT_NAME)
	@$(CC) $(CFLAGS) $(SRCS) $(LIBFT_F)$(LIBFT_NAME) -o $(NAME)

clean:
	@rm $(NAME)
	@make clean -C $(LIBFT_F)

fclean: clean
	@make fclean -C $(LIBFT_F)

re: fclean all

.PHONY: all clean fclean re
