# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrehberg <maxrehberg@posteo.de>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/19 20:16:06 by mrehberg          #+#    #+#              #
#    Updated: 2022/09/08 17:50:01 by mrehberg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c ft_printf_utils.c

LIBFT = ../libft/*.o

LIBFT_DIR = ../libft

OBJS = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g

all: $(NAME)

$(NAME): Makefile $(OBJS) make_libft ft_printf.h
	@ar -rcs $(NAME) $(OBJS) $(LIBFT)

make_libft:
	@make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f *.out
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re make_libft