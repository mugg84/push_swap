/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_fn.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmughedd <mmughedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:26:29 by mmughedd          #+#    #+#             */
/*   Updated: 2024/01/03 14:34:14 by mmughedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*create_node(char *value, int index, int len)
{
	t_stack	*new_node;
	bool	is_median;

	is_median = false;
	if (index != 0 && len <= index * 2)
		is_median = true;
	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->value = (int)atoi(value);
	new_node->index = index;
	new_node->median = is_median;
	new_node->next = NULL;
	new_node->target = NULL;
	new_node->cost = 0;
	return (new_node);
}

void	init_stack(t_stack **stack_a, char **args, int i, int len)
{
	int		j;
	t_stack	*node;

	j = 0;
	*stack_a = create_node(args[i], j++, len);
	if (!*stack_a)
		return ;
	node = *stack_a;
	while (args[++i])
	{
		node->next = create_node(args[i], j++, len);
		node = node->next;
	}
}

void	create_stack(t_stack **stack_a, int argc, char **argv)
{
	char	**args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	while (args[len])
		len++;
	if (argc != 2)
		len--;
	init_stack(stack_a, args, i, len);
}

void	free_stack(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*head;

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

void	reset_data(t_stack *stack)
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
