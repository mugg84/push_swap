/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmughedd <mmughedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:25:04 by mmughedd          #+#    #+#             */
/*   Updated: 2024/01/01 16:59:35 by mmughedd         ###   ########.fr       */
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

int	is_ascending(stack_list **stack)
{
	stack_list	*temp;
	int	value1;
	int	value2;

	if (!*stack)
		return (0);
	temp = *stack;
	while (temp)
	{
		value1 = temp->value;
		temp = temp->next;
		if (temp)
			value2 = temp->value;
		if (value1 > value2)
			return (0);
	}
	return (1);
}

int	is_descending(stack_list **stack)
{
	stack_list	*temp;
	int	value1;
	int	value2;

	if (!*stack)
		return (0);
	temp = *stack;
	while (temp)
	{
		value1 = temp->value;
		temp = temp->next;
		if (temp)
			value2 = temp->value;
		if (value1 < value2)
			return (0);
	}
	return (1);
}

stack_list	*find_node(stack_list *stack, int index)
{
	if (!stack)
		return (NULL);
	while (stack->next && stack->index != index)
		stack = stack->next;
	return (stack);
}

int	find_lowest_num(stack_list *stack)
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

	if (!stack)
		return ;
	if (add_sub == '+')
		unit = 1;
	else
		unit = -1;
	if (!stack->next)
		stack->index += unit;
	else
		while (stack)
		{
			stack->index += unit;
			stack = stack->next;
		}
}

void	find_biggest_smallest(stack_list *stack, stack_list **biggest, stack_list **smallest)
{
	*biggest = stack;
	*smallest = stack;
	if (!stack)
		return ;
	while (stack && stack->value)
	{
		if ((stack)->value > (*biggest)->value)
			(*biggest) = stack;
		else if ((stack)->value < ((*smallest))->value)
			(*smallest) = stack;
		stack = (stack)->next;
	}
	(*biggest)->is_biggest = true;
	(*smallest)->is_smallest = true;
}

void	find_target(stack_list *node, stack_list *stack)
{
	stack_list	*target = {NULL};
	stack_list	*smallest = {NULL};
	stack_list	*biggest = {NULL};

	if (!stack || !node)
		return ;
	find_biggest_smallest(stack, &biggest, &smallest);
	if (node->value > biggest->value || node->value < smallest->value)
		node->target = biggest;
	else
	{	while (stack->value > node->value)
			stack = stack->next;
		target = stack;
		while (stack && stack->value)
		{
			if (stack->value < node->value && stack->value > target->value)
				target = stack;
			stack = stack->next;
		}
		node->target = target;
	}
}

void	calc_cost(stack_list *stack_a, stack_list *stack_b)
{
	while (stack_a)
	{
		find_target(stack_a, stack_b);
		//printf("value: %d, target: %d\n", stack_a->value, (stack_a->target)->value);
		stack_a = stack_a->next;
	}

}

void	solve_big(stack_list **stack_a, stack_list **stack_b, int len)
{
	calc_cost(*stack_a, *stack_b);
	len = 0;
	len += 1;
	//if (!is_ascending(stack_a))
	//	solve_three(stack_a);
	//while (stack_b)
	//	move_node(stack_b, stack_a);
}

void	reset_data(stack_list *stack)
{
	bool		is_median;
	int			index;
	int			len;

	if (!stack)
		return ;
	len = stack_len(stack);
	while (stack)
	{
		is_median = false;
		index = (stack)->index;
		if (index != 0 && len <= index * 2)
			is_median = true;
		(stack)->is_biggest = false;
		(stack)->is_cheapest = false;
		(stack)->is_smallest = false;
		(stack)->median = is_median;
		stack->target = NULL;
		stack = (stack)->next;
	}
}