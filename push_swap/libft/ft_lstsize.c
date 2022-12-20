/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrehberg <maxrehberg@posteo.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 20:32:07 by mrehberg          #+#    #+#             */
/*   Updated: 2022/09/05 13:21:26 by mrehberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		count;
	t_list	*buf;

	buf = lst;
	count = 1;
	while (buf -> next != NULL)
	{
		buf = buf -> next;
		count++;
	}
	return (count);
}
