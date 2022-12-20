/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrehberg <maxrehberg@posteo.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 15:15:26 by mrehberg          #+#    #+#             */
/*   Updated: 2022/08/26 21:26:56 by mrehberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief returns 1 if character is a number or a-z or A-Z
 */
int	ft_isalnum(int character)
{
	if (character >= '0' && character <= '9')
		return (1);
	if (character >= 'A' && character <= 'Z')
		return (1);
	if (character >= 'a' && character <= 'z')
		return (1);
	return (0);
}
