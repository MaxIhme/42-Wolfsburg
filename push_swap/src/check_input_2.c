/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrehberg <maxrehberg@posteo.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 19:47:15 by mrehberg          #+#    #+#             */
/*   Updated: 2022/09/09 20:23:57 by mrehberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief if the input string has a character that's not a number 
 * it returns 1 
 * -> i.e. 234g56 or 342o u865
 * and if the sign is not at the beginning it returns 1 
 * -> i.e. 894735+435 or 9-
 * -12 or +4 is ok -> returns 0
 */
int	is_no_num(char *nums)
{
	int	run;
	int	flag_now_only_num;

	flag_now_only_num = 0;
	run = 0;
	while (nums[run])
	{
		if (flag_now_only_num == 1 && !ft_isdigit(nums[run]))
			return (1);
		if (nums[run] == '+' || nums[run] == '-' || ft_isdigit(nums[run]))
			flag_now_only_num = 1;
		if (!ft_isdigit(nums[run]))
		{
			if (!(nums[run] == '+' || nums[run] == '-'))
				return (1);
		}
		run++;
	}
	return (0);
}
