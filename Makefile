# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angsanch <angsanch@student.42madrid.c      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/13 18:29:24 by angsanch          #+#    #+#              #
#    Updated: 2024/07/21 03:14:05 by angsanch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc

CFLAGS=-Wall -Werror -Wextra -g

C_FILES = src/main.c \
			src/tools/tpipex.c \
			src/tools/command.c \
			src/exec/run.c \
			src/exec/child.c \
			src/exec/parent.c \

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
