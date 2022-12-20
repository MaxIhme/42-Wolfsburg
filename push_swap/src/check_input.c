/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrehberg <maxrehberg@posteo.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 21:57:11 by mrehberg          #+#    #+#             */
/*   Updated: 2022/09/18 22:38:43 by mrehberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief checks input arguments that are separate numbers 
 * @return 1 if allright -> -23 34 +0
 */
int	check_input_separate(int argc, char **argv)
{
	int		nums;
	long	buf;
	int		buf2;

	if (argc == 2)
		return (0);
	nums = 1;
	while (nums < argc)
	{
		if (is_no_num(argv[nums]))
			error();
		buf = ft_atol(argv[nums]);
		if (buf > 2147483647 || buf < -2147483648)
			error();
		buf2 = is_zero(argv[nums], 0);
		if (buf + buf2 == 0)
			return (0);
		nums++;
	}
	return (1);
}

/**
 * @brief if the str is zero, returns 1
 * "0" 		or 
 * "  +0 " 	or 
 * "  -0"
 * func returns 1
 * not for "- 0 "
 */
int	is_zero(char *c, int i)
{
	while (c[i])
	{
		if (c[i] == ' ')
		{
			if (!(c[i + 1] == ' ' || c[i + 1] == '+'
					|| c[i + 1] == '-' || c[i + 1] == '0'))
				return (0);
		}
		else if ((c[i] == '+' || c[i] == '-'))
		{
			if (c[i + 1] != '0')
				return (0);
		}
		else if (c[i] == '0')
		{
			if (!(c[i + 1] != '0' || c[i + 1] != ' ' || c[i + 1] == 0))
				return (0);
		}
		else
			return (0);
		i++;
	}
	return (1);
}

/**
 * @brief only for 2d chars, not for lists !!
 */
int	look_for_end(char **two_d_char)
{
	int	i;

	i = 0;
	while (two_d_char[i] != NULL)
	{
		i++;
	}
	return (i);
}

/**
 * @brief checks input arguments that are in " "
 * @returns 1 if allright
 */
int	check_input_string(int argc, char **argv, int count)		
{
	char	**nums;
	long	buf;
	int		buf2;
	int		max_nums;

	if (argc != 2)
		return (0);
	nums = ft_split(&argv[1][0], ' ');
	max_nums = look_for_end(nums);
	while (count < max_nums)
	{
		buf = ft_atol(nums[count]);
		if (buf > 2147483647 || buf < -2147483648 || is_no_num(nums[count]))
		{
			free_two_d_str_split(nums);
			error();
		}
		buf2 = is_zero(nums[count], 0);
		if (buf + buf2 == 0)
			return (0);
		count++;
	}
	free_two_d_str_split(nums);
	return (1);
}

/**
 * @brief checks input arguments (only numbers with/-out + - sign are allowed)
 * @param $ ./a.out "-2147483648 0 +0 -0 2 3 987 54" -> 
 * is ok 	-> string_flag is 1
 * @param $ ./a.out 12 23 0 +0 -0 -76 				-> 
 * is ok 	-> string_flag is 0
 * @param $ only one argument (argc < 2) -> is not ok -> string_flag is -1
 * @param $ ./a.out "-2147483648 0 +0 one 2 3 987 54" -> 
 * is not ok -> string_flag is -1
 * @param $ if not ok prints "error" and exits program
 */
void	check_input(int argc, char **argv, int *string_flag)
{
	*string_flag = -1;
	if (argc < 2)
		exit(0);
	if (check_input_separate(argc, argv))
		*string_flag = 0;
	else if (check_input_string(argc, argv, 0))
		*string_flag = 1;
	if (*string_flag == -1)
		error();
}
