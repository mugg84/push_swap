/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmughedd <mmughedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:24:02 by mmughedd          #+#    #+#             */
/*   Updated: 2024/01/02 09:19:41 by mmughedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../libft/libft.h"
#include "unistd.h"
#include "limits.h"
#include <stdbool.h>

typedef struct z_list
{
	int				value;
	int				index;
	int				cost;
	bool			median;
	bool			is_biggest;
	bool			is_smallest;
	bool			is_cheapest;
	struct z_list	*next;
	struct z_list	*target;
} stack_list;

int	check_args(int argc, char **argv);

int	is_unique(char **args, int i);

int	is_digit(char *arg);

int	is_int(char *arg);

void	free_stack(stack_list **stack);

void	create_stack(stack_list **stack_a, int argc, char **argv);

void	init_stack(stack_list **stack_a, char **args, int i, int len);

stack_list	*create_node(char *value, int index, int len);

int	is_ascending(stack_list **stack);

int	is_descending(stack_list **stack);

void	swap(stack_list **stack);

void	push(stack_list **stack1, stack_list **stack2);

void	rotate(stack_list **stack);

void	rev_rotate(stack_list **stack);

void	solve_stack(stack_list **stack_a, stack_list **stack_b);

int	stack_len(stack_list *stack);

void	solve_small(stack_list **stack_a, stack_list **stack_b, int len);

void	solve_three(stack_list **stack_a);

int	find_lowest_num(stack_list *stack);

void	change_index(stack_list *stack, char add_sub);

stack_list	*find_node(stack_list *stack, int index);

stack_list	*find_cheapest(stack_list *stack);

void	solve_four_five(stack_list **stack_a, stack_list **stack_b, int len);

void	find_target(stack_list *node, stack_list *stack);

void	calc_cost(stack_list *stack_a, stack_list *stack_b, int len);

int	single_cost(int	index, bool median, int len);

void	solve_big(stack_list **stack_a, stack_list **stack_b, int len);

void	reset_data(stack_list *stack);

void	find_biggest_smallest(stack_list *stack, stack_list **biggest, stack_list **smallest);

#endif