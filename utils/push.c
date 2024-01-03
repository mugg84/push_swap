/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmughedd <mmughedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:08:41 by mmughedd          #+#    #+#             */
/*   Updated: 2024/01/03 14:27:29 by mmughedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push(t_stack **stack1, t_stack **stack2, char a_or_b)
{
	t_stack	*temp;

	if (!*stack1)
		return ;
	temp = *stack1;
	if ((*stack1)->next)
		*stack1 = (*stack1)->next;
	else
		*stack1 = NULL;
	change_index(*stack2, '+');
	temp->next = *stack2;
	*stack2 = temp;
	change_index(*stack1, '-');
	reset_data(*stack1);
	reset_data(*stack2);
	print_move("p", a_or_b);
}
