# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrehberg <maxrehberg@posteo.de>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/26 20:02:54 by mrehberg          #+#    #+#              #
#    Updated: 2022/11/14 11:27:57 by mrehberg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := so_long

SRC_DIR := src/
MAP := maps/simple_map_l.ber
LIBFT := libft/libft.a
MLX_DIR := minilibx_opengl_20191021
MLX_DIR_LIX := minilibx-linux
MLX := $(MLX_DIR)/libmlx.a
MLX_LIX := $(MLX_DIR_LIX)/libmlx.a

SRC := $(SRC_DIR)so_long.c \
 $(SRC_DIR)checks.c \
 $(SRC_DIR)checks_2.c \
 $(SRC_DIR)checks_path.c \
 $(SRC_DIR)draw_window.c \
 $(SRC_DIR)move_player.c \
 $(SRC_DIR)additional.c

OBJS := $(SRC:.c=.o)

CC := gcc

C_FLAGS := -Wall -Werror -Wextra

C_TEST_FLAGS := -Wall -Wextra -g

all: $(NAME)

$(NAME): Makefile $(SRC)
	make -C $(MLX_DIR)
	make -C libft
	$(CC) $(C_FLAGS) $(SRC) $(LIBFT) $(MLX) -framework OpenGL -framework AppKit -lz -o $(NAME)

e: $(NAME)
	./$(NAME) $(MAP)

l: $(NAME)
	leaks -atExit --list -- ./$(NAME) $(MAP)

make_test: Makefile $(SRC)
	make -C $(MLX_DIR)
	make -C libft
	$(CC) $(C_TEST_FLAGS) $(SRC) $(LIBFT) $(MLX) -framework OpenGL -framework AppKit -lz -o $(NAME)

t: make_test
	./$(NAME) $(MAP)

make_linux: Makefile $(SRC)
	make -C $(MLX_DIR_LIX)
	make -C libft
	$(CC) $(C_TEST_FLAGS) $(SRC) $(LIBFT) $(MLX_LIX) -lXext -lX11 -o $(NAME)

lix: make_linux
	./$(NAME) $(MAP)

tl: make_test
	export MallocStackLogging=0
	leaks -atExit --list -- ./$(NAME) $(MAP)

norm:
	norminette img/
	norminette libft/
	norminette maps/
	norminette src/

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f *.out
	make fclean -C libft

re: fclean t

.PHONY: all clean fclean re make_linux make_test l e tl t