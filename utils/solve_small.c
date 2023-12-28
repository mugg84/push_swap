/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_small.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmughedd <mmughedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 15:27:55 by mmughedd          #+#    #+#             */
/*   Updated: 2023/12/28 15:21:51 by mmughedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	solve_small(stack_list **stack_a, stack_list **stack_b, int len)
{
	if (len <= 2)
		swap(stack_a);
	else if (len == 3)
		solve_three(stack_a);
}

void	solve_three(stack_list **stack_a)
{
	int	first;
	int	second;
	int	third;

	while (!is_ordered(stack_a))
	{

		first = (find_node(*stack_a, 0)->value);
		second = (find_node(*stack_a, 1)->value);
		third = (find_node(*stack_a, 2)->value);
		if ((first > second && second < third) || (first > second && second > third))
			swap(stack_a);
		else
			rev_rotate(stack_a);
	}
}