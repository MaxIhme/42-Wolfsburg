/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrehberg <maxrehberg@posteo.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 15:55:26 by mrehberg          #+#    #+#             */
/*   Updated: 2022/09/02 20:45:41 by mrehberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_ps_list **stack)
{
	*stack = next_node(*stack);
}

void	reverse_rotate(t_ps_list **stack)
{
	*stack = return_last_node(*stack);
}

void	rotate_both(t_ps_list **stack_a, t_ps_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}

void	reverse_rotate_both(t_ps_list **stack_a, t_ps_list **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
}
