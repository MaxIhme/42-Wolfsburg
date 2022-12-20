/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_swap_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrehberg <maxrehberg@posteo.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 18:12:35 by mrehberg          #+#    #+#             */
/*   Updated: 2022/09/05 13:19:51 by mrehberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief the func checks where act_num (stack_a -> position) is in stack_a.
 * if it's in the top of the stack it returns 0. If it can't find the 
 * number, it returns -1;
 */
int	position_in_stack(t_ps_list **stack_a, int act_num)
{
	int			i;
	t_ps_list	*buf;

	i = 0;
	buf = *stack_a;
	while (buf -> position != act_num)
	{
		if (buf == *stack_a && i != 0)
			return (-1);
		buf = next_node(buf);
		i++;
	}
	return (i);
}

/**
 * @return $ return 0 if the act_num is closer to the top of stack 
 * hen the num after act_num
 */
int	which_is_closer(t_ps_list **stack_a, int act_num)
{
	int	position;
	int	position_next;
	int	stack_size;

	stack_size = return_num_of_nodes(*stack_a);
	if (stack_size == 1)
		return (0);
	position = position_in_stack(stack_a, act_num);
	position_next = position_in_stack(stack_a, (act_num + 1));
	if (position > (stack_size / 2))
		position = stack_size - position;
	if (position_next > (stack_size / 2))
		position_next = stack_size - position_next;
	if (position < position_next)
		return (0);
	return (1);
}

/**
 * @return $ 0 if it is faster to the number with rotation ---
 * return 1 if it is faster to the number with reverse rotation ---
 * return -1 if the numer is on spot
 */
int	which_direction(t_ps_list **stack_a, int number)
{
	int	nodes_in_stack;
	int	position;

	nodes_in_stack = return_num_of_nodes(*stack_a);
	position = position_in_stack(stack_a, number);
	if (position == 0 || position == -1)
		return (-1);
	if (position < (nodes_in_stack / 2))
		return (0);
	return (1);
}

/**
 * @brief the function goes to num in the shortest direction (ra or rra)
 * and pushes the number into stack_b
 */
void	go_to_num(t_ps_list **stack_a, t_ps_list **stack_b, int num)
{
	int	dir;

	dir = which_direction(stack_a, num);
	if (dir == 0)
	{
		while ((*stack_a)-> position != num)
		{
			rotate(stack_a);
			ft_printf("ra\n");
		}
	}
	else if (dir == 1)
	{
		while ((*stack_a)-> position != num)
		{
			reverse_rotate(stack_a);
			ft_printf("rra\n");
		}
	}
	push_src_to_dest(stack_a, stack_b);
	ft_printf("pb\n");
}

/**
 * @brief the function wants to get numbers in a sortet order 
 * into stack_b (lowest first). It then pushes everything back into stack_a.
 * the function looks for the next two numbers to put into stack_b and
 * calculates wich one is closer to the top of the stack, either ra or rra.
 * if it's the next number that is closer it goes there and puts it
 * into stack_b. Then it looks again for the next two numbers. 
 * If the other is closer, for example you start with 0, next number is 1
 * and the second next is 2. If 2 is closer to the top of the stack than 1
 * it goes to 2, then pb and then it goes to 1 and pb and sb. 
 * Then is starts all over. When 1 is closer, it goes to 1, pb and then it 
 * starts all over.
 */
void	short_way_next_two(t_ps_list **stack_a, t_ps_list **stack_b)
{
	int	act_num;
	int	order;

	act_num = 0;
	while (*stack_a != NULL)
	{
		order = which_is_closer(stack_a, act_num);
		if (order == 1)
			go_to_num(stack_a, stack_b, (act_num + 1));
		if (*stack_a != NULL)
			go_to_num(stack_a, stack_b, act_num);
		if (order == 1)
		{
			act_num = act_num + 2;
			swap(stack_b);
			ft_printf("sb\n");
		}
		else
			act_num++;
	}
	while (*stack_b != NULL)
	{
		push_src_to_dest(stack_b, stack_a);
		ft_printf("pa\n");
	}
}
