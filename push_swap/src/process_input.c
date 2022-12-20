/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrehberg <maxrehberg@posteo.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 18:14:37 by mrehberg          #+#    #+#             */
/*   Updated: 2022/09/02 20:48:11 by mrehberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief
 * 
 * @param str_split 
 */
void	free_two_d_str_split(char **str_split)
{
	int	max_rows;
	int	count;

	count = 0;
	max_rows = look_for_end(str_split);
	while (count < max_rows)
	{
		free(str_split[count]);
		count++;
	}
	free(str_split);
}

t_ps_list	*populate_stack_with_string(t_ps_list *stack_a, char **argv)
{
	char		**nums;
	int			buf;
	int			max_nums;
	int			act_num;
	t_ps_list	*buf_list;

	act_num = 0;
	nums = ft_split(&argv[1][0], ' ');
	max_nums = look_for_end(nums);
	buf = ft_atoi(&nums[act_num][0]);
	stack_a = new_node(buf);
	act_num++;
	while (act_num < max_nums)
	{
		buf = ft_atoi(&nums[act_num][0]);
		buf_list = new_node(buf);
		add_to_end_of_list(stack_a, buf_list);
		act_num++;
	}
	free_two_d_str_split(nums);
	return (stack_a);
}

t_ps_list	*populate_stack_sepr_nums(t_ps_list *stack_a, char **argv, int argc)
{
	int			buf;
	int			act_num;
	t_ps_list	*buf_list;

	act_num = 1;
	buf = ft_atoi(&argv[act_num][0]);
	stack_a = new_node(buf);
	act_num++;
	while (act_num < argc)
	{
		buf = ft_atoi(&argv[act_num][0]);
		buf_list = new_node(buf);
		add_to_end_of_list(stack_a, buf_list);
		act_num++;
	}
	return (stack_a);
}

void	calculate_positions(t_ps_list *stack_a)
{
	t_ps_list	*slow;
	t_ps_list	*fast;

	slow = stack_a;
	while (slow != NULL)
	{
		fast = stack_a;
		while (fast != NULL)
		{
			if (fast -> content < slow -> content)
			{
				slow -> position = slow -> position + 1;
			}
			fast = next_node(fast);
		}
		slow = next_node(slow);
	}
}

/**
 * @brief process input
 * @return t_ps_list* 
 */
t_ps_list	*prc_in(int argc, char **argv, int str_flag, t_ps_list *stack_a)
{
	if (str_flag)
		stack_a = populate_stack_with_string(stack_a, argv);
	else
		stack_a = populate_stack_sepr_nums(stack_a, argv, argc);
	if (!check_for_duplicates(stack_a))
	{
		clear_stackloop_list(stack_a);
		error();
	}
	calculate_positions(stack_a);
	return (stack_a);
}
