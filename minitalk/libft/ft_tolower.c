/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrehberg <maxrehberg@posteo.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 12:44:11 by mrehberg          #+#    #+#             */
/*   Updated: 2022/05/03 21:52:08 by mrehberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int upper)
{
	if (upper >= 'A' && upper <= 'Z')
		return (upper +32);
	return (upper);
}
