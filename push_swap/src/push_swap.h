/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrehberg <maxrehberg@posteo.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 20:14:37 by mrehberg          #+#    #+#             */
/*   Updated: 2022/09/09 20:14:23 by mrehberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_printf/ft_printf.h"

typedef struct s_ps_list{
	int					content;
	int					position;
	struct s_ps_list	*next;
}	t_ps_list;

//----------- main.c

void		error(void);
int			main(int argc, char **argv);

//----------- check_input.c

int			check_input_separate(int argc, char **argv);
int			is_zero(char *c, int i);
int			look_for_end(char **two_d_char);
int			check_input_string(int argc, char **argv, int count);
void		check_input(int argc, char **argv, int *string_flag);

//----------- check_input_2.c

int			is_no_num(char *nums);

//----------- handling_lists.c

t_ps_list	*new_node(int content);
t_ps_list	*return_last_node(t_ps_list *stack_loop);
t_ps_list	*add_to_end_of_list(t_ps_list *list, t_ps_list *new_node);
void		clear_stackloop_list(t_ps_list *stack);
void		list_to_stackloop(t_ps_list *stack);

//----------- handling_lists_2.c

t_ps_list	*next_node(t_ps_list *node);
void		print_stack(t_ps_list *stack);
t_ps_list	*ptr_to_node_number(t_ps_list *stack, int num);
t_ps_list	*del_node_from_stackloop(t_ps_list *stackloop);
int			return_num_of_nodes(t_ps_list *stack_loop);

//----------- process_input.c

void		free_two_d_str_split(char **str_split);
t_ps_list	*populate_stack_with_string(t_ps_list *stack_a, char **argv);
t_ps_list	*populate_stack_sepr_nums(t_ps_list *stack_a,
				char **argv, int argc);
void		calculate_positions(t_ps_list *stack_a);
t_ps_list	*prc_in(int argc, char **argv, int str_flag, t_ps_list *stack_a);

//----------- instructions.c

void		swap(t_ps_list **stack);
void		swap_both(t_ps_list **stack_a, t_ps_list **stack_b);

//----------- instructions_2.c

int			help_push_src(int *num_nodes_src, t_ps_list **src_stack,
				t_ps_list **next_node_src, t_ps_list **last_node);
int			help_push_dest(int *num_nodes_dest, t_ps_list **dest_stack,
				t_ps_list **src_start, t_ps_list **last_node);
void		push_src_to_dest(t_ps_list **src_stack, t_ps_list **dest_stack);

//----------- instructions_3.c

void		rotate(t_ps_list **stack);
void		reverse_rotate(t_ps_list **stack);
void		rotate_both(t_ps_list **stack_a, t_ps_list **stack_b);
void		reverse_rotate_both(t_ps_list **stack_a, t_ps_list **stack_b);

//----------- check_stack.c

int			is_sorted(t_ps_list **stack_a);
int			check_for_duplicates(t_ps_list *stack_a);

//----------- rotate_swap_sort.c

int			position_in_stack(t_ps_list **stack_a, int act_num);
int			which_is_closer(t_ps_list **stack_a, int act_num);
int			which_direction(t_ps_list **stack_a, int number);
void		go_to_num(t_ps_list **stack_a, t_ps_list **stack_b, int num);
void		short_way_next_two(t_ps_list **stack_a, t_ps_list **stack_b);

//----------- three_five_sort.c

void		three_sort_decide_helper(t_ps_list **stack_a);
void		three_sort_decide(int spot_zero, int spot_one, int spot_two,
				t_ps_list **stack_a);
void		three_sort(t_ps_list **stack_a);
void		five_sort(t_ps_list **stack_a, t_ps_list **stack_b);

//----------- radix_sort.c

void		push_back(t_ps_list **stack_a, t_ps_list **stack_b);
void		push_or_rotate(t_ps_list **stack_a, t_ps_list **stack_b, int bit);
void		radix_sort(t_ps_list **stack_a, t_ps_list **stack_b);

//----------- atol.c

long		ft_atol(const char *str);

#endif
