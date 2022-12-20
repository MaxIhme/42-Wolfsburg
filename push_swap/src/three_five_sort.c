/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_five_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrehberg <maxrehberg@posteo.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 11:38:03 by mrehberg          #+#    #+#             */
/*   Updated: 2022/09/02 21:25:06 by mrehberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_sort_decide_helper(t_ps_list **stack_a)
{
	swap(stack_a);
	rotate(stack_a);
	ft_printf("sa\nra\n");
}

void	three_sort_decide(int spot_zero, int spot_one, int spot_two,
			t_ps_list **stack_a)
{
	if ((spot_zero < spot_one) && (spot_one < spot_two))
		ft_printf("ra\nrra\n");
	else if ((spot_zero < spot_two) && (spot_two < spot_one))
		three_sort_decide_helper(stack_a);
	else if ((spot_one < spot_zero) && (spot_zero < spot_two))
	{
		swap(stack_a);
		ft_printf("sa\n");
	}
	else if ((spot_two < spot_zero) && (spot_zero < spot_one))
	{
		reverse_rotate(stack_a);
		ft_printf("rra\n");
	}
	else if ((spot_one < spot_two) && (spot_two < spot_zero))
	{
		rotate(stack_a);
		ft_printf("ra\n");
	}
	else if ((spot_two < spot_one) && (spot_one < spot_zero))
	{
		swap(stack_a);
		reverse_rotate(stack_a);
		ft_printf("sa\nrra\n");
	}
}

void	three_sort(t_ps_list **stack_a)
{
	t_ps_list	*buf;
	int			spot_zero;
	int			spot_one;
	int			spot_two;

	spot_zero = (*stack_a)-> position;
	buf = next_node(*stack_a);
	spot_one = buf -> position;
	buf = next_node(buf);
	spot_two = buf -> position;
	three_sort_decide(spot_zero, spot_one, spot_two, stack_a);
}

void	five_sort(t_ps_list **stack_a, t_ps_list **stack_b)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		if (((*stack_a)-> position == 0) || ((*stack_a)-> position == 1))
		{
			push_src_to_dest(stack_a, stack_b);
			ft_printf("pb\n");
			i++;
		}
		else
		{
			rotate(stack_a);
			ft_printf("ra\n");
		}
	}
	if ((*stack_b)-> position == 0)
	{
		swap(stack_b);
		ft_printf("sb\n");
	}
	three_sort(stack_a);
	push_back(stack_a, stack_b);
	ft_printf("pa\npa\n");
}
