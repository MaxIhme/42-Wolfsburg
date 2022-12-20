# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrehberg <maxrehberg@posteo.de>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/15 11:18:20 by mrehberg          #+#    #+#              #
#    Updated: 2022/12/05 10:46:41 by mrehberg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := minitalk
SERVER := server
CLIENT := client

SERVER_BONUS := server_bonus
CLIENT_BONUS := client_bonus

SRC_DIR := src/
LIBFT := libft/libft.a

SRC := $(SRC_DIR)server.c \
 $(SRC_DIR)client.c \

SRC_SERVER := $(SRC_DIR)server.c
SRC_CLIENT := $(SRC_DIR)client.c

SRC_SERVER_BONUS := $(SRC_DIR)server_bonus.c
SRC_CLIENT_BONUS := $(SRC_DIR)client_bonus.c

OBJS := $(SRC:.c=.o)

CC := gcc

C_FLAGS := -Wall -Wextra -Werror

C_TEST_FLAGS := -Wall -Wextra -fsanitize=address

all: $(NAME) $(SERVER) $(CLIENT)

bonus: $(NAME) $(SERVER_BONUS) $(CLIENT_BONUS)

$(NAME): Makefile libft

$(SERVER): $(SRC_SERVER)
	$(CC) $(C_FLAGS) $(SRC_SERVER) $(LIBFT) -o $@

$(CLIENT): $(SRC_CLIENT)
	$(CC) $(C_FLAGS) $(SRC_CLIENT) $(LIBFT) -o $@

$(SERVER_BONUS): $(SRC_SERVER_BONUS)
	$(CC) $(C_FLAGS) $(SRC_SERVER_BONUS) $(LIBFT) -o $@

$(CLIENT_BONUS): $(SRC_CLIENT_BONUS)
	$(CC) $(C_FLAGS) $(SRC_CLIENT_BONUS) $(LIBFT) -o $@

libft:
	make -C libft

clean:
	rm -f $(OBJS)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	rm -f server
	rm -f client
	rm -f server_bonus
	rm -f client_bonus
	rm -f *.out
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re libft