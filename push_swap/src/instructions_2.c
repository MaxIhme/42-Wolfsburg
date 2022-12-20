/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrehberg <maxrehberg@posteo.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 09:16:18 by mrehberg          #+#    #+#             */
/*   Updated: 2022/09/02 20:44:46 by mrehberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	help_push_src(int *num_nodes_src, t_ps_list **src_stack,
		t_ps_list **next_node_src, t_ps_list **last_node)
{
	if (*num_nodes_src == 0)
		return (1);
	else if (*num_nodes_src == 1)
	{
		(*src_stack)-> next = NULL;
		*src_stack = NULL;
	}
	else if (*num_nodes_src >= 2)
	{
		*next_node_src = next_node(*src_stack);
		*last_node = return_last_node(*src_stack);
		(*last_node)-> next = *next_node_src;
		*src_stack = *next_node_src;
	}
	return (0);
}

int	help_push_dest(int *num_nodes_dest, t_ps_list **dest_stack,
		t_ps_list **src_start, t_ps_list **last_node)
{
	if (*num_nodes_dest >= 1)
	{
		*last_node = return_last_node(*dest_stack);
		(*last_node)-> next = *src_start;
		(*src_start)-> next = *dest_stack;
		*dest_stack = *src_start;
	}
	else if (*num_nodes_dest == 0)
	{
		*dest_stack = *src_start;
		(*dest_stack)-> next = *dest_stack;
	}
	return (0);
}

/**
 * @brief stackloop means you can give it stacks only with a looped end
 * @param $ it puts the first node of src_stack between the last and the first
 * node of dest_stack
 * @return $ the new src stack (the new dest_stack is the last node
 *  of the old dest_stack)
 */
void	push_src_to_dest(t_ps_list **src_stack, t_ps_list **dest_stack)
{
	t_ps_list	*last_node;
	t_ps_list	*next_node_src;
	t_ps_list	*src_start;
	int			num_nodes_src;
	int			num_nodes_dest;

	num_nodes_src = return_num_of_nodes(*src_stack);
	num_nodes_dest = return_num_of_nodes(*dest_stack);
	src_start = *src_stack;
	if (help_push_src(&num_nodes_src, src_stack, &next_node_src, &last_node))
		return ;
	help_push_dest(&num_nodes_dest, dest_stack, &src_start, &last_node);
}
