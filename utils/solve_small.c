/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_small.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmughedd <mmughedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 15:27:55 by mmughedd          #+#    #+#             */
/*   Updated: 2023/12/26 13:26:01 by mmughedd         ###   ########.fr       */
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
	printf("waitforit");
}