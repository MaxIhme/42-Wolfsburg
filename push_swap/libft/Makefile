# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrehberg <maxrehberg@posteo.de>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/26 13:06:01 by mrehberg          #+#    #+#              #
#    Updated: 2022/08/26 19:19:31 by mrehberg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

TEST = ../Libft_testfiles/test.a

TESTC = ../Libft_testfiles/test.c

SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c\
 ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c\
 ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c\
 ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c\
 ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c\
 ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c\
 ft_putnbr_fd.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c\
 ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c


OBJS = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g

all: $(NAME)

$(NAME):	$(OBJS) Makefile
	ar -rcs $(NAME) $(OBJS)

ex:
	$(CC) $(CFLAGS) -o $(TEST) $(SRC) $(TESTC)
	./$(TEST)

test:
	$(CC) $(CFLAGS) -o $(TEST) $(SRC) $(TESTC)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f *.out

re: fclean all

.PHONY: all clean fclean re