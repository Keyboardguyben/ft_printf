# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    MAKEFILE                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgilliea <bgilliea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/24 12:34:50 by bgilliea          #+#    #+#              #
#    Updated: 2022/11/28 11:05:49 by bgilliea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
INCLUDE		= ft_printf.h
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = src/ft_printf_hex.c \
	src/ft_printf.c	\
	src/ft_printf_nbr.c \
	src/ft_printf_unbr.c \
	src/ft_printf_ptr.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
		ar rcs $(NAME) $(OBJ)

%.o: %.c  $(INCLUDE)
		@echo "Compiling: $<"
		$(CC) $(CFLAGS) -c $< -o $@

clean :
			rm -rf $(OBJ)

fclean: clean
			rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re