/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_big.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmughedd <mmughedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:03:42 by mmughedd          #+#    #+#             */
/*   Updated: 2024/01/03 14:52:35 by mmughedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	set_top_push(t_stack **s_a, t_stack **s_b, t_stack *cheap, t_stack *tar)
{
	if (cheap->median == tar->median)
	{
		while (cheap->index != 0 && tar->index != 0)
		{
			if (!cheap->median)
				rotate_both(s_a, s_b);
			else
				rev_rotate_both(s_a, s_b);
		}
	}
	while (cheap->index != 0)
	{
		if (!cheap->median)
			rotate(s_a, 'a');
		else
			rev_rotate(s_a, 'a');
	}
	while (tar->index != 0)
	{
		if (!tar->median)
			rotate(s_b, 'b');
		else
			rev_rotate(s_b, 'b');
	}
	push(s_a, s_b, 'b');
}

void	move_node(t_stack **stack_a, t_stack **stack_b, int len)
{
	t_stack	*cheapest;
	t_stack	*target;

	calc_cost(*stack_a, *stack_b, len);
	cheapest = find_cheapest(*stack_a);
	target = cheapest->target;
	set_top_push(stack_a, stack_b, cheapest, target);
}

void	solve_big(t_stack **stack_a, t_stack **stack_b, int len)
{
	t_stack	*biggest;

	push(stack_a, stack_b, 'b');
	push(stack_a, stack_b, 'b');
	while (len > 3)
	{
		move_node(stack_a, stack_b, len);
		len = stack_len(*stack_a);
	}
	if (!is_ascending(stack_a))
		solve_three(stack_a);
	while (*stack_b)
		move_back(stack_b, stack_a);
	find_biggest(*stack_a, &biggest);
	while (!is_ascending(stack_a))
	{
		if (!biggest->median)
			rotate(stack_a, 'a');
		else
			rev_rotate(stack_a, 'a');
	}
}

void	smallest_big(t_stack *node, t_stack *stack)
{
	t_stack	*target;
	t_stack	*smallest;
	t_stack	*biggest;

	if (!stack || !node)
		return ;
	find_biggest(stack, &biggest);
	find_smallest(stack, &smallest);
	if (node->value > biggest->value || node->value < smallest->value)
		node->target = smallest;
	else
	{
		while (stack->value < node->value)
			stack = stack->next;
		target = stack;
		while (stack && stack->value)
		{
			if (stack->value > node->value && stack->value < target->value)
				target = stack;
			stack = stack->next;
		}
		node->target = target;
	}
}

void	move_back(t_stack **stack_b, t_stack **stack_a)
{
	if (!*stack_a || !*stack_b)
		return ;
	smallest_big(*stack_b, *stack_a);
	while (((*stack_b)->target)->index != 0)
	{
		if (!((*stack_b)->target)->median)
			rotate(stack_a, 'a');
		else
			rev_rotate(stack_a, 'a');
	}
	push(stack_b, stack_a, 'a');
}
