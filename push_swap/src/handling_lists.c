/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_lists.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrehberg <maxrehberg@posteo.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 18:08:59 by mrehberg          #+#    #+#             */
/*   Updated: 2022/09/02 20:42:56 by mrehberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief allocates memory, position is set to 0, 
 * 
 * @param content is set to content
 * @return t_ps_list* pointer to the list, NULL if alloc fails
 */
t_ps_list	*new_node(int content)
{
	t_ps_list	*new_node;

	new_node = malloc(sizeof(t_ps_list));
	if (!new_node)
		return (NULL);
	new_node -> content = content;
	new_node -> position = 0;
	new_node -> next = NULL;
	return (new_node);
}

t_ps_list	*return_last_node(t_ps_list *stack_loop)
{
	t_ps_list	*start;

	if (stack_loop == NULL)
		return (NULL);
	start = stack_loop;
	while (stack_loop -> next != NULL && stack_loop -> next != start)
	{
		stack_loop = stack_loop -> next;
	}
	return (stack_loop);
}

t_ps_list	*add_to_end_of_list(t_ps_list *list, t_ps_list *new_node)
{
	t_ps_list	*buf;

	buf = return_last_node(list);
	buf -> next = new_node;
	return (list);
}

void	clear_stackloop_list(t_ps_list *stack)
{
	t_ps_list	*start;
	t_ps_list	*buf;

	start = stack;
	buf = stack;
	stack = next_node(stack);
	free (buf);
	while (stack != NULL && stack != start)
	{
		buf = stack;
		stack = next_node(stack);
		free(buf);
	}
}

void	list_to_stackloop(t_ps_list *stack)
{
	t_ps_list	*buf;

	if (stack == NULL)
		return ;
	buf = stack;
	stack = return_last_node(stack);
	stack -> next = buf;
}
