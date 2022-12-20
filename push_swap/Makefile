# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrehberg <maxrehberg@posteo.de>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/26 20:02:54 by mrehberg          #+#    #+#              #
#    Updated: 2022/09/13 16:55:19 by mrehberg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = src/main.c \
	src/check_input.c \
	src/handling_lists.c \
	src/handling_lists_2.c \
	src/process_input.c \
	src/instructions.c \
	src/instructions_2.c \
	src/instructions_3.c \
	src/rotate_swap_sort.c \
	src/check_stack.c \
	src/three_five_sort.c \
	src/radix_sort.c \
	src/ft_atol.c \
	src/check_input_2.c

PRINTF_LIBFT = ft_printf/libftprintf.a

PRINTF_LIBFT_DIR = ft_printf/

CHECKER = ../checker_Mac

CC = gcc

CFLAGS = -Wall -Werror -Wextra

C_TEST_FLAGS = -Wall -Wextra -g

TEST_NUMBERS = -461 -3 0 -80 251 403 -75 -422 193 233 172 384 472 264 +2147483647

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): Makefile $(OBJS) make_printf_libft
	$(CC) $(CFLAGS) $(OBJS) $(PRINTF_LIBFT) -o $(NAME)

make_test: Makefile $(SRC) make_printf_libft
	@$(CC) $(CFLAGS) $(SRC) $(PRINTF_LIBFT) -o $(NAME)

make_printf_libft:
	@make -C $(PRINTF_LIBFT_DIR)

e: make_test
	./$(NAME) "$(TEST_NUMBERS)"

t: make_test
	@echo "\033[32m------------------------------ Start ------------------------------\033[37m"
	@echo "\033[32m 3 nums not more than 3 moves \033[37m"
	@echo "\033[32m 5 nums not more than 12 moves \033[37m"
	@echo "\033[32m 100 and 500 random nums in best moves \033[37m"
	@num=0;for number in $(TEST_NUMBERS) ; do ((num = num + 1)); done;\
	echo "---------------------------------" $$num "nums Input"; 
	@echo "checker_Mac: str args" 
	@./$(NAME) "$(TEST_NUMBERS)" | wc -l | tr -d '\012\015' ; echo " moves"
	@./$(NAME) "$(TEST_NUMBERS)" | $(CHECKER) "$(TEST_NUMBERS)"
	@echo "checker_Mac: separate args"
	@./$(NAME) $(TEST_NUMBERS) | wc -l | tr -d '\012\015' ; echo " moves"
	@./$(NAME) $(TEST_NUMBERS) | $(CHECKER) "$(TEST_NUMBERS)"
	@echo "\033[32m----- Leaks -----\033[37m"
	@echo "str args" 
	@leaks -atExit -- ./$(NAME) "$(TEST_NUMBERS)" | grep "leaks for" | awk '{print $$3, " ", $$4}'
	@echo "separate args"
	@leaks -atExit -- ./$(NAME) $(TEST_NUMBERS) | grep "leaks for" | awk '{print $$3, " ", $$4}'
	@echo "\n"
	@./$(NAME) "$(TEST_NUMBERS)" | sed -n 1,10p
	@echo "\n"

l: make_test
	leaks -atExit -- ./$(NAME) "$(TEST_NUMBERS)"

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f *.out
	make fclean -C $(PRINTF_LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re make_printf_libft make_test e t l