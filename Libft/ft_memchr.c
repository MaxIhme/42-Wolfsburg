/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrehberg <maxrehberg@posteo.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 15:48:43 by mrehberg          #+#    #+#             */
/*   Updated: 2022/05/16 15:21:08 by mrehberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	chr;
	unsigned char	*st;
	size_t			i;

	chr = (unsigned char)c;
	st = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (st[i] == chr)
		{
			return (&st[i]);
		}
		i++;
	}
	return (NULL);
}
