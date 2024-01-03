/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmughedd <mmughedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:07:28 by mmughedd          #+#    #+#             */
/*   Updated: 2024/01/03 14:29:33 by mmughedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rev_rotate(t_stack **stack, char a_or_b)
{
	t_stack	*second_last;
	t_stack	*last;
	t_stack	*temp;
	int		len;

	len = stack_len(*stack);
	second_last = find_node(*stack, len - 2);
	last = find_node(*stack, len - 1);
	if (!second_last || !last || second_last == last)
		return ;
	temp = *stack;
	*stack = last;
	(*stack)->next = temp;
	second_last->next = NULL;
	change_index(*stack, '+');
	(*stack)->index = 0;
	print_move("rr", a_or_b);
}

void	rev_rotate_both(t_stack **stack1, t_stack **stack2)
{
	rev_rotate(stack1, 0);
	rev_rotate(stack2, 0);
	print_move("rr", 'r');
}
