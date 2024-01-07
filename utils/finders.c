/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmughedd <mmughedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 13:57:38 by mmughedd          #+#    #+#             */
/*   Updated: 2024/01/07 09:41:42 by mmughedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*find_node(t_stack *stack, int index)
{
	if (!stack)
		return (NULL);
	while (stack->next && stack->index != index)
		stack = stack->next;
	return (stack);
}

int	find_lowest_num(t_stack *stack)
{
	int	index;
	int	value;

	if (!stack)
		return (0);
	index = 0;
	value = (stack)->value;
	while (stack)
	{
		if ((stack)->value < value)
		{
			value = (stack)->value;
			index = (stack)->index;
		}
		stack = (stack)->next;
	}
	return (index);
}

void	find_biggest(t_stack *stack, t_stack **biggest)
{
	*biggest = stack;
	if (!stack)
		return ;
	while (stack)
	{
		if ((stack)->value > (*biggest)->value)
			(*biggest) = stack;
		stack = (stack)->next;
	}
}

void	find_smallest(t_stack *stack, t_stack **smallest)
{
	*smallest = stack;
	if (!stack)
		return ;
	while (stack)
	{
		if ((stack)->value < ((*smallest))->value)
			(*smallest) = stack;
		stack = (stack)->next;
	}
}

void	find_target(t_stack *node, t_stack *stack)
{
	t_stack	*target;
	t_stack	*smallest;
	t_stack	*biggest;

	if (!stack || !node)
		return ;
	find_biggest(stack, &biggest);
	find_smallest(stack, &smallest);
	if (node->value > biggest->value || node->value < smallest->value)
		node->target = biggest;
	else
	{
		while (stack->value > node->value)
			stack = stack->next;
		target = stack;
		while (stack)
		{
			if (stack->value < node->value && stack->value > target->value)
				target = stack;
			stack = stack->next;
		}
		node->target = target;
	}
}
