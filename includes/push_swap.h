/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmughedd <mmughedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:24:02 by mmughedd          #+#    #+#             */
/*   Updated: 2024/01/04 13:56:41 by mmughedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "unistd.h"
# include "limits.h"
# include <stdbool.h>

typedef struct z_list
{
	int				value;
	int				index;
	int				cost;
	bool			median;
	struct z_list	*next;
	struct z_list	*target;
}	t_stack;

t_stack	*create_node(char *value, int index, int len);

t_stack	*find_node(t_stack *stack, int index);

t_stack	*find_cheapest(t_stack *stack);

int		check_args(int argc, char **argv);

int		is_unique(char **args, int i);

int		is_digit(char *arg);

int		is_int(char *arg);

int		is_ascending(t_stack **stack);

int		is_descending(t_stack **stack);

int		stack_len(t_stack *stack);

int		find_lowest_num(t_stack *stack);

int		cost(int index, bool median, int len);

void	free_stack(t_stack **stack);

void	create_stack(t_stack **stack_a, int argc, char **argv);

void	init_stack(t_stack **stack_a, char **args, int i, int len);

void	swap(t_stack **stack, char a_or_b);

void	push(t_stack **stack1, t_stack **stack2, char a_or_b);

void	rotate(t_stack **stack, char a_or_b);

void	rev_rotate(t_stack **stack, char a_or_b);

void	push_swap(t_stack **stack_a, t_stack **stack_b);

void	print_move(char *move, char a_or_b);

void	solve_small(t_stack **stack_a, t_stack **stack_b, int len);

void	solve_three(t_stack **stack_a);

void	change_index(t_stack *stack, char add_sub);

void	solve_five(t_stack **stack_a, t_stack **stack_b, int len);

void	find_target(t_stack *node, t_stack *stack);

void	calc_cost(t_stack *stack_a, t_stack *stack_b, int len);

void	solve_big(t_stack **stack_a, t_stack **stack_b, int len);

void	reset_data(t_stack *stack);

void	find_biggest(t_stack *stack, t_stack **biggest);

void	find_smallest(t_stack *stack, t_stack **smafind_smallest);

void	swap_both(t_stack **stack1, t_stack **stack2);

void	rotate_both(t_stack **stack1, t_stack **stack2);

void	rev_rotate_both(t_stack **stack1, t_stack **stack2);

void	move_back(t_stack **stack_a, t_stack **stack_b);

void	smallest_big(t_stack *node, t_stack *stack);

void	move_node(t_stack **stack_a, t_stack **stack_b, int len);

//TODO: delete
void	loop(t_stack *a, t_stack *b);

#endif