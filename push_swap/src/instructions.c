/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrehberg <maxrehberg@posteo.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 15:47:33 by mrehberg          #+#    #+#             */
/*   Updated: 2022/09/02 20:46:40 by mrehberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief swap the first two elements of stack
 */
void	swap(t_ps_list **stack)
{
	t_ps_list	*first_node;
	int			buf;

	if (return_num_of_nodes(*stack) <= 1)
		return ;
	first_node = next_node(*stack);
	buf = first_node -> content;
	first_node -> content = (*stack)-> content;
	(*stack)-> content = buf;
	buf = first_node -> position;
	first_node -> position = (*stack)-> position;
	(*stack)-> position = buf;
}

void	swap_both(t_ps_list **stack_a, t_ps_list **stack_b)
{
	swap(stack_a);
	swap(stack_b);
}
