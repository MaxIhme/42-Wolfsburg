/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrehberg <maxrehberg@posteo.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:50:41 by mrehberg          #+#    #+#             */
/*   Updated: 2022/09/05 13:20:47 by mrehberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief new gets addet to the end of lst
 * lst stays at the beginning of lst
 */
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*buf;

	buf = *lst;
	if (*lst == NULL)
		*lst = new;
	else
	{
		while (buf -> next != NULL)
		{
			buf = buf -> next;
		}
		buf -> next = new;
	}
}
