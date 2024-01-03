/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmughedd <mmughedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:08:13 by mmughedd          #+#    #+#             */
/*   Updated: 2024/01/03 14:25:20 by mmughedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_stack **stack, char a_or_b)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*rest;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = (*stack)->next;
	second->index = 0;
	rest = second->next;
	first->next = rest;
	first->index = 1;
	*stack = second;
	(*stack)->next = first;
	print_move("s", a_or_b);
}

void	swap_both(t_stack **stack1, t_stack **stack2)
{
	swap(stack1, 0);
	swap(stack2, 0);
	print_move("s", 's');
}
