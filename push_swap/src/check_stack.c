/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrehberg <maxrehberg@posteo.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 18:38:16 by mrehberg          #+#    #+#             */
/*   Updated: 2022/09/02 20:36:05 by mrehberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @return $ 1 if is sorted
 */
int	is_sorted(t_ps_list **stack_a)
{
	t_ps_list	*buf;
	t_ps_list	*buf_next;
	t_ps_list	*start;

	start = *stack_a;
	buf = *stack_a;
	buf_next = next_node(buf);
	while (buf_next != start)
	{
		if (!(buf -> content < buf_next -> content))
			return (0);
		buf = buf_next;
		buf_next = next_node(buf_next);
	}
	return (1);
}

int	check_for_duplicates(t_ps_list *stack_a)
{
	t_ps_list	*run_node;
	int			content;
	int			next_content;

	while (stack_a -> next != NULL)
	{
		run_node = next_node(stack_a);
		content = stack_a -> content;
		while (run_node != NULL)
		{
			next_content = run_node -> content;
			if (content == next_content)
				return (0);
			run_node = next_node(run_node);
		}
		stack_a = next_node(stack_a);
	}
	return (1);
}
