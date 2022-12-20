/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_lists_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrehberg <maxrehberg@posteo.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 21:39:31 by mrehberg          #+#    #+#             */
/*   Updated: 2022/09/02 20:41:44 by mrehberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ps_list	*next_node(t_ps_list *stack)
{
	stack = stack -> next;
	return (stack);
}

void	print_stack(t_ps_list *stack)
{
	t_ps_list	*start;

	if (stack == NULL)
	{
		ft_printf("null\n");
		return ;
	}
	ft_printf("---------------------\n");
	start = stack;
	while (stack -> next != start && stack -> next != NULL)
	{
		ft_printf("%d\n", stack -> content);
		stack = next_node(stack);
	}
	ft_printf("%d\n", stack -> content);
	ft_printf("---------------------\n");
}

t_ps_list	*ptr_to_node_number(t_ps_list *stack, int num)
{
	int	count;

	count = 0;
	while (count < num)
	{
		stack = next_node(stack);
		count++;
	}
	return (stack);
}

/**
 * @brief deletes node from a stackloop and 
 * returns ptr to the next node
 */
t_ps_list	*del_node_from_stackloop(t_ps_list *stackloop)
{
	t_ps_list	*next_node;
	t_ps_list	*last_node;

	next_node = stackloop -> next;
	last_node = return_last_node(stackloop);
	free (stackloop);
	last_node -> next = next_node;
	return (next_node);
}

/**
 * @brief can handle stack and loop
 * 
 * @return $ int number of nodes
 */
int	return_num_of_nodes(t_ps_list *stack_loop)
{
	t_ps_list	*start;
	int			count;

	if (stack_loop == NULL)
		return (0);
	count = 0;
	start = stack_loop;
	while (stack_loop -> next != NULL && stack_loop -> next != start)
	{
		stack_loop = stack_loop -> next;
		count++;
	}
	count++;
	return (count);
}
