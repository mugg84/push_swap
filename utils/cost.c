/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmughedd <mmughedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:11:52 by mmughedd          #+#    #+#             */
/*   Updated: 2024/01/03 14:52:50 by mmughedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	cost(int index, bool median, int len)
{
	int	s_cost;

	if (!median)
		s_cost = index;
	else
		s_cost = len - index;
	return (s_cost);
}

void	calc_cost(t_stack *stack_a, t_stack *stack_b, int len)
{
	int	cost_a;
	int	cost_b;
	int	tot_cost;

	while (stack_a)
	{
		find_target(stack_a, stack_b);
		cost_a = cost(stack_a->index, stack_a->median, len);
		cost_b = cost((stack_a->target)->index, (stack_a->target)->median, len);
		if (stack_a->median != (stack_a->target)->median)
			tot_cost = cost_a + cost_b;
		else
		{
			if (cost_a > cost_b)
				tot_cost = cost_a;
			else
				tot_cost = cost_b;
		}
		stack_a->cost = tot_cost;
		stack_a = stack_a->next;
	}
}

t_stack	*find_cheapest(t_stack *stack)
{
	t_stack	*cheapest;

	cheapest = stack;
	while (stack)
	{
		if (stack->cost < cheapest->cost)
			cheapest = stack;
		stack = stack->next;
	}
	return (cheapest);
}
