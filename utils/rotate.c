/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmughedd <mmughedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:06:38 by mmughedd          #+#    #+#             */
/*   Updated: 2024/01/04 13:04:55 by mmughedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate(t_stack **stack, char a_or_b)
{
	t_stack	*head;
	t_stack	*last;
	t_stack	*temp;
	int		len;

	head = *stack;
	len = stack_len(*stack);
	last = find_node(*stack, len - 1);
	if (!head || !last || head == last)
		return ;
	temp = *stack;
	*stack = head->next;
	last->next = temp;
	temp->next = NULL;
	change_index(*stack, '-');
	last = find_node(*stack, len - 1);
	last->index = len - 1;
	print_move("r", a_or_b);
}

void	rotate_both(t_stack **stack1, t_stack **stack2)
{
	rotate(stack1, 0);
	rotate(stack2, 0);
	print_move("r", 'r');
}
