/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmughedd <mmughedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:25:04 by mmughedd          #+#    #+#             */
/*   Updated: 2024/01/05 13:28:58 by mmughedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_move(char *move, char a_or_b)
{
	if (a_or_b)
		ft_printf("%s%c\n", move, a_or_b);
}

int	is_ascending(t_stack **stack)
{
	t_stack	*temp;
	int		value1;
	int		value2;

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

int	stack_len(t_stack *stack)
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

void	change_index(t_stack *stack, char add_sub)
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
	{
		while (stack)
		{
			stack->index += unit;
			stack = stack->next;
		}
	}
}
