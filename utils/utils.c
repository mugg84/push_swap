/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmughedd <mmughedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:25:04 by mmughedd          #+#    #+#             */
/*   Updated: 2024/01/02 13:23:22 by mmughedd         ###   ########.fr       */
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

// int	is_descending(stack_list **stack)
// {
// 	stack_list	*temp;
// 	int	value1;
// 	int	value2;

// 	if (!*stack)
// 		return (0);
// 	temp = *stack;
// 	while (temp)
// 	{
// 		value1 = temp->value;
// 		temp = temp->next;
// 		if (temp)
// 			value2 = temp->value;
// 		if (value1 < value2)
// 			return (0);
// 	}
// 	return (1);
// }

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

// void	find_biggest_smallest(stack_list *stack, stack_list **biggest, stack_list **smallest)
// {
// 	*biggest = stack;
// 	*smallest = stack;
// 	if (!stack)
// 		return ;
// 	while (stack && stack->value)
// 	{
// 		if ((stack)->value > (*biggest)->value)
// 			(*biggest) = stack;
// 		else if ((stack)->value < ((*smallest))->value)
// 			(*smallest) = stack;
// 		stack = (stack)->next;
// 	}
// }

void	find_biggest(stack_list *stack, stack_list **biggest)
{
	*biggest = stack;
	if (!stack)
		return ;
	while (stack && stack->value)
	{
		if ((stack)->value > (*biggest)->value)
			(*biggest) = stack;
		stack = (stack)->next;
	}
}

void	find_smallest(stack_list *stack, stack_list **smallest)
{
	*smallest = stack;
	if (!stack)
		return ;
	while (stack && stack->value)
	{
		if ((stack)->value < ((*smallest))->value)
			(*smallest) = stack;
		stack = (stack)->next;
	}
}

void	find_target(stack_list *node, stack_list *stack)
{
	stack_list	*target = {NULL};
	stack_list	*smallest = {NULL};
	stack_list	*biggest = {NULL};

	if (!stack || !node)
		return ;
	find_biggest(stack, &biggest);
	find_smallest(stack, &smallest);
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

int	single_cost(int	index, bool median, int len)
{
	int	s_cost;

	if (!median)
		s_cost = index;
	else
		s_cost = len - index;
	return (s_cost);
}

void	calc_cost(stack_list *stack_a, stack_list *stack_b, int len)
{
	int	cost_a;
	int	cost_b;
	int	tot_cost;

	while (stack_a)
	{
		find_target(stack_a, stack_b);
		cost_a = single_cost(stack_a->index, stack_a->median, len);
		cost_b = single_cost((stack_a->target)->index, (stack_a->target)->median, len);
		if (stack_a->median != (stack_a->target)->median)
			tot_cost = cost_a + cost_b;
		else
			if (cost_a > cost_b)
				tot_cost = cost_a;
			else
				tot_cost = cost_b;
		stack_a->cost = tot_cost;
		stack_a = stack_a->next;
	}
}

stack_list	*find_cheapest(stack_list *stack)
{
	stack_list	*cheapest;

	cheapest = stack;
	while (stack)
	{
		if (stack->cost < cheapest->cost)
			cheapest = stack;
		stack = stack->next;
	}
	return (cheapest);
}

void	set_top_push(stack_list **s_a, stack_list **s_b, stack_list *cheap, stack_list *tar)
{
	if (cheap->median == tar->median)
	{
		while (cheap->index != 0 && tar->index != 0)
		{
			if (!cheap->median)
				rotate_both(s_a, s_b);
			else
				rev_rotate_both(s_a, s_b);
		}
	}
	while (cheap->index != 0)
	{
		if (!cheap->median)
			rotate(s_a, 'a');
		else
			rev_rotate(s_a, 'a');
	}
	while (tar->index != 0)
	{
		if (!tar->median)
			rotate(s_b, 'b');
		else
			rev_rotate(s_b, 'b');
	}
	push(s_a, s_b, 'b');
}

void	solve_big(stack_list **stack_a, stack_list **stack_b, int len)
{
	stack_list	*cheapest;
	stack_list	*target;
	stack_list	*biggest;

	push(stack_a, stack_b, 'b');
	push(stack_a, stack_b, 'b');
	while (len > 3)
	{
		calc_cost(*stack_a, *stack_b, len);
		cheapest = find_cheapest(*stack_a);
		target = cheapest->target;
		set_top_push(stack_a,stack_b ,cheapest, target);
		len = stack_len(*stack_a);
	}
	if (!is_ascending(stack_a))
		solve_three(stack_a);
	while (*stack_b)
		move_node(stack_b, stack_a);
	find_biggest(*stack_a, &biggest);
	while (!is_ascending(stack_a))
	{
		if (!biggest->median)
			rotate(stack_a, 'a');
		else
			rev_rotate(stack_a, 'a');
	}
}

void	smallest_big(stack_list *node, stack_list *stack)
{
	stack_list	*target;
	stack_list	*smallest;
	stack_list	*biggest;

	if (!stack || !node)
		return ;
	find_biggest(stack, &biggest);
	find_smallest(stack, &smallest);
	if (node->value > biggest->value || node->value < smallest->value)
		node->target = smallest;
	else
	{	while (stack->value < node->value)
			stack = stack->next;
		target = stack;
		while (stack && stack->value)
		{
			if (stack->value > node->value && stack->value < target->value)
				target = stack;
			stack = stack->next;
		}
		node->target = target;
	}
}

void	move_node(stack_list **stack_b, stack_list **stack_a)
{
	if (!*stack_a || !*stack_b)
		return ;
	smallest_big(*stack_b, *stack_a);
	while (((*stack_b)->target)->index != 0)
	{
		if (!((*stack_b)->target)->median)
			rotate(stack_a, 'a');
		else
			rev_rotate(stack_a, 'a');
	}
	push(stack_b, stack_a, 'a');
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
		(stack)->median = is_median;
		stack->target = NULL;
		stack->cost = 0;
		stack = (stack)->next;
	}
}