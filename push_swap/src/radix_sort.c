/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrehberg <maxrehberg@posteo.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 08:17:45 by mrehberg          #+#    #+#             */
/*   Updated: 2022/09/08 15:03:11 by mrehberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_back(t_ps_list **stack_a, t_ps_list **stack_b)
{
	while (*stack_b != NULL)
	{
		push_src_to_dest(stack_b, stack_a);
		ft_printf("pa\n");
	}
}

void	push_or_rotate(t_ps_list **stack_a, t_ps_list **stack_b, int bit)
{
	if ((((*stack_a)-> position >> bit) & 1) == 0)
	{
		push_src_to_dest(stack_a, stack_b);
		ft_printf("pb\n");
	}
	else
	{
		rotate(stack_a);
		ft_printf("ra\n");
	}
}

void	radix_sort(t_ps_list **stack_a, t_ps_list **stack_b)
{
	int			nodes;
	int			bits;
	int			node;
	int			bit;

	bit = 0;
	bits = 0;
	nodes = return_num_of_nodes(*stack_a);
	while (((nodes - 1) >> bits) != 0)
		bits++;
	while (bit < bits)
	{
		node = 0;
		while (node < nodes)
		{
			push_or_rotate(stack_a, stack_b, bit);
			node++;
		}
		push_back(stack_a, stack_b);
		bit++;
	}
}
