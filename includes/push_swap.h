/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmughedd <mmughedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:24:02 by mmughedd          #+#    #+#             */
/*   Updated: 2023/12/28 14:33:32 by mmughedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../libft/libft.h"
#include "unistd.h"
#include "limits.h"

typedef struct z_list
{
	int				value;
	int				index;
	struct z_list	*next;
} stack_list;

int	check_args(int argc, char **argv);

int	is_unique(char **args, int i);

int	is_digit(char *arg);

int	is_int(char *arg);

void	free_stack(stack_list **stack);

void	create_stack(stack_list **stack_a, int argc, char **argv);

void	init_stack(stack_list **stack_a, char **args, int i);

stack_list	*create_node(char *value, int index);

int	is_ordered(stack_list **stack);

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

#endif