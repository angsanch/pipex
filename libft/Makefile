# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angsanch <angsanch@student.42madrid.c      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/13 18:29:06 by angsanch          #+#    #+#              #
#    Updated: 2024/06/20 03:44:43 by angsanch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COMPILE_BASIC = true
COMPILE_PRINTF = true
COMPILE_LINKED = true

CC=gcc

CFLAGS=-Werror -Wall -Wextra

BASIC_SOURCE = src/basic/my_strupcase.c \
			src/basic/my_getnbr.c \
			src/basic/my_str_islower.c \
			src/basic/my_str_isnum.c \
			src/basic/my_str_isalnum.c \
			src/basic/my_strcpy.c \
			src/basic/my_put_nbr.c \
			src/basic/my_strcmp.c \
			src/basic/convert_base.c \
			src/basic/my_strlowcase.c \
			src/basic/my_showstr.c \
			src/basic/my_strncmp.c \
			src/basic/my_str_isprintable.c \
			src/basic/my_showmem.c \
			src/basic/my_putstr.c \
			src/basic/my_strcat.c \
			src/basic/my_strncpy.c \
			src/basic/my_strdup.c \
			src/basic/my_strlen.c \
			src/basic/my_putchar.c \
			src/basic/my_strcapitalize.c \
			src/basic/my_getnbr_base.c \
			src/basic/my_strncat.c \
			src/basic/my_revstr.c \
			src/basic/my_strstr.c \
			src/basic/my_str_isalpha.c \
			src/basic/my_str_isupper.c \
			src/basic/my_putnbr_base.c \
			src/basic/my_memcmp.c \
			src/basic/my_memset.c \
			src/basic/my_strchr.c \
			src/basic/my_strrchr.c \
			src/basic/my_memcpy.c \
			src/basic/my_strjoin.c \
			src/basic/my_calloc.c \
			src/basic/my_split.c \
			src/basic/my_coolersplit_utils.c \
			src/basic/my_coolersplit.c \
			src/basic/my_memjoin.c \
			src/basic/my_memchr.c \
			src/basic/my_memmove.c \
			src/basic/gnl.c \
			src/basic/my_revmem.c \
			src/basic/report_error.c \
			src/basic/my_strreplace.c \
			src/basic/pointer_arrays.c \


PRINTF_SOURCE = src/ft_printf/args.c \
			src/ft_printf/f_functions.c \
			src/ft_printf/genericf.c \
			src/ft_printf/integers.c \
			src/ft_printf/integer_tools.c \
			src/ft_printf/parameter_utils.c \
			src/ft_printf/parse_parameter.c \
			src/ft_printf/simple.c \
			src/ft_printf/strings.c \


LINKED_SOURCE = src/linked_lists/creation.c \
			src/linked_lists/deletion.c \
			src/linked_lists/simple_operations.c \
			src/linked_lists/iter_tools.c \
			src/linked_lists/modifications.c \
			src/linked_lists/sort.c \


C_FILES =

HEADERS =

ifeq ($(COMPILE_BASIC), true)
	C_FILES += $(BASIC_SOURCE)
	HEADERS += include/basic.h
endif
ifeq ($(COMPILE_LINKED), true)
	C_FILES += $(LINKED_SOURCE)
	HEADERS += include/linked_list.h
endif
ifeq ($(COMPILE_PRINTF), true)
	C_FILES += $(PRINTF_SOURCE)
	HEADERS += include/my_printf.h
endif

O_FILES = $(C_FILES:.c=.o)

ASSETS_O = $(ASSETS:=.o)

EXTERN_H = $(subst include/,../include/,$(HEADERS))

NAME=libft.a

$(NAME): $(O_FILES) $(ASSETS_O)
	ar -rsc $(NAME) $(O_FILES) $(ASSETS_O)
	mkdir -p ../include
	cp $(HEADERS) ../include

all: $(NAME)

clean:
	rm -f $(O_FILES)
	rm -f $(ASSETS_O)

fclean: clean
	rm -f $(EXTERN_H)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
