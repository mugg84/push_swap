/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_small.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmughedd <mmughedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 15:27:55 by mmughedd          #+#    #+#             */
/*   Updated: 2024/01/02 13:22:10 by mmughedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	solve_three(stack_list **stack_a)
{
	int	first;
	int	second;
	int	third;

	while (!is_ascending(stack_a))
	{

		first = (find_node(*stack_a, 0)->value);
		second = (find_node(*stack_a, 1)->value);
		third = (find_node(*stack_a, 2)->value);
		if ((first > second && second < third) || (first > second && second > third))
			swap(stack_a, 'a');
		else
			rev_rotate(stack_a, 'a');
	}
}

void	solve_four_five(stack_list **stack_a, stack_list **stack_b, int len)
{
	int	lowest_ind;
	stack_list	*lowest_node;

	while (len > 3)
	{
		lowest_ind = find_lowest_num(*stack_a);
		lowest_node = find_node(*stack_a, lowest_ind);
		while (lowest_node->index)
		{
			if (lowest_ind <= 2)
				rotate(stack_a, 'a');
			else
				rev_rotate(stack_a, 'a');
		}
		push(stack_a, stack_b, 'b');
		len = stack_len(*stack_a);
	}
	solve_three(stack_a);
	while (*stack_b)
		push(stack_b, stack_a, 'a');
}

void	solve_small(stack_list **stack_a, stack_list **stack_b, int len)
{
	if (len <= 2)
		swap(stack_a, 'a');
	else if (len == 3)
		solve_three(stack_a);
	else
		solve_four_five(stack_a, stack_b, len);
}

