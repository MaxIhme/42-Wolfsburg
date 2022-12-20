/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrehberg <maxrehberg@posteo.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 19:30:45 by mrehberg          #+#    #+#             */
/*   Updated: 2022/09/13 13:59:06 by mrehberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	ft_printf("Error\n");
	exit(1);
}

void	sort(t_ps_list **stack_a, t_ps_list **stack_b)
{
	int	nodes;

	if (is_sorted(stack_a))
		return ;
	nodes = return_num_of_nodes(*stack_a);
	if (nodes == 3)
		three_sort(stack_a);
	else if (nodes == 5)
		five_sort(stack_a, stack_b);
	else if (nodes < 99)
		short_way_next_two(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
}

/**
 * @brief 
 * 
 * @param str_flag == 0 when input is separate numbers
 * str_flag == 1 when input is in one string
 * @param argv 
 * @return int 
 */
int	main(int argc, char **argv)
{
	int			str_flag;
	t_ps_list	*stack_a;
	t_ps_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (stack_b)
		return (0);
	check_input(argc, argv, &str_flag);
	stack_a = prc_in(argc, argv, str_flag, stack_a);
	list_to_stackloop(stack_a);
	sort(&stack_a, &stack_b);
	clear_stackloop_list(stack_a);
	return (0);
}
