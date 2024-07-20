# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angsanch <angsanch@student.42madrid.c      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/13 18:29:24 by angsanch          #+#    #+#              #
#    Updated: 2024/07/21 01:13:00 by angsanch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc

CFLAGS=-Wall -Werror -Wextra

C_FILES =

O_FILES = $(C_FILES:.c=.o)

LIB = libft/libft.a

NAME=pipex

$(NAME): $(LIB) $(O_FILES)
	$(CC) $(CFLAGS) -o $(NAME) $(O_FILES) $(LIB)

all: $(NAME)

clean:
	make -C libft clean
	rm -f $(O_FILES) test_$(NAME)

fclean: clean
	make -C libft fclean
	rm -f $(NAME)

$(LIB):
	make -C libft

re: fclean all

.PHONY: all clean fclean re
