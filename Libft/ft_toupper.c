/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrehberg <maxrehberg@posteo.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 12:39:32 by mrehberg          #+#    #+#             */
/*   Updated: 2022/05/03 21:51:34 by mrehberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int low)
{
	if (low >= 'a' && low <= 'z')
		return (low -32);
	return (low);
}
