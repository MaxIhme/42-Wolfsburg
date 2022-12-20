/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrehberg <maxrehberg@posteo.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 19:13:54 by mrehberg          #+#    #+#             */
/*   Updated: 2022/09/05 13:21:01 by mrehberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*buf_1;
	t_list	*buf_2;

	if (!lst || !del)
		return ;
	buf_1 = *lst;
	while (buf_1 != NULL)
	{
		buf_2 = buf_1->next;
		del(buf_1->content);
		free(buf_1);
		buf_1 = buf_2;
	}
	*lst = NULL;
}
