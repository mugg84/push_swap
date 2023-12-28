/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmughedd <mmughedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:25:04 by mmughedd          #+#    #+#             */
/*   Updated: 2023/12/26 14:03:50 by mmughedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_stack(stack_list **stack)
{
	stack_list	*temp;
	stack_list	*head;

	if (!stack)
		return ;
	head = *stack;
	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

int	is_ordered(stack_list **stack)
{
	stack_list	*temp;
	int	value1;
	int	value2;

	if (!stack)
		return (0);
	temp = *stack;
	while (temp && temp->value)
	{
		value1 = temp->value;
		temp = temp->next;
		if (temp && temp->value)
			value2 = temp->value;
		if (value1 > value2)
			return (0);
	}
	return (1);
}

stack_list	*find_last_node(stack_list *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

stack_list	*find_second_last_node(stack_list *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next && (stack->next)->next)
		stack = stack->next;
	return (stack);
}

// stack_list	*find_node(stack_list *stack, int index)
// {
// 	if (!stack)
// 		return (NULL);
// 	while (stack->next && stack->index != index)
// 		stack = stack->next;
// 	return (stack);
// }

int	find_smallest_num(stack_list *stack)
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
			value =(stack)->value;
			index = (stack)->index;
		}
		stack = (stack)->next;
	}
	return (index);
}

int	stack_len(stack_list *stack)
{
	int	len;

	if (!stack)
		return (0);
	len = 1;
	while (stack->next)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}

void	change_index(stack_list *stack, char add_sub)
{
	int	unit;

	if (add_sub == '+')
		unit = 1;
	else
		unit = -1;
	if (!stack->next)
		stack->index += unit;
	while (stack)
	{
		stack->index += unit;
		stack = stack->next;
	}
}
