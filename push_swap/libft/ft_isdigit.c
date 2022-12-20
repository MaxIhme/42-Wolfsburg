/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrehberg <maxrehberg@posteo.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 10:59:51 by mrehberg          #+#    #+#             */
/*   Updated: 2022/08/26 21:28:38 by mrehberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief returns 1 if character is a digit
 */
int	ft_isdigit(int character)
{
	if (character >= '0' && character <= '9')
		return (1);
	return (0);
}
