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

void	calc_cost(t_stack *s_a, t_stack *s_b, int len_a, int len_b)
{
	int	cost_a;
	int	cost_b;
	int	tot_cost;

	while (s_a)
	{
		find_target(s_a, s_b);
		cost_a = cost(s_a->index, s_a->median, len_a);
		cost_b = cost((s_a->target)->index, (s_a->target)->median, len_b);
		if (s_a->median != (s_a->target)->median)
			tot_cost = cost_a + cost_b;
		else
		{
			if (cost_a > cost_b)
				tot_cost = cost_a;
			else
				tot_cost = cost_b;
		}
		s_a->cost = tot_cost;
		s_a = s_a->next;
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
