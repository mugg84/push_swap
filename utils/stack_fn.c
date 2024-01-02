/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_fn.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmughedd <mmughedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:26:29 by mmughedd          #+#    #+#             */
/*   Updated: 2024/01/02 11:59:43 by mmughedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

stack_list	*create_node(char *value, int index, int len)
{
	stack_list	*new_node;
	bool		is_median;

	is_median = false;
	if (index != 0 && len <= index * 2)
		is_median = true;
	new_node = malloc(sizeof(stack_list));
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

void	init_stack(stack_list **stack_a, char **args, int i, int len)
{
	int			j;
	stack_list	*node;

	j = 0;
	*stack_a = create_node(args[i], j++, len);
	if (!*stack_a)
		return ;
	node = *stack_a;
	while (args[++i])
	{
		node->next =  create_node(args[i], j++, len);
		node = node->next;
	}
}

void	create_stack(stack_list **stack_a, int argc, char **argv)
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

void	print_move(char *move, char a_or_b)
{
	if (a_or_b)
		printf("%s%c\n", move, a_or_b);
}

void	swap(stack_list **stack, char a_or_b)
{
	stack_list	*first;
	stack_list	*second;
	stack_list	*rest;

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

void	push(stack_list **stack1, stack_list **stack2, char a_or_b)
{
	stack_list	*temp;

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

void	rotate(stack_list **stack, char a_or_b)
{
	stack_list	*head;
	stack_list	*last;
	stack_list	*temp;
	int	len;

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

void	rev_rotate(stack_list **stack, char a_or_b)
{
	stack_list	*second_last;
	stack_list	*last;
	stack_list	*temp;
	int	len;

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

void	swap_both(stack_list **stack1, stack_list **stack2)
{
	swap(stack1, 0);
	swap(stack2, 0);
	print_move("ss", 0);
}

void	rotate_both(stack_list **stack1, stack_list **stack2)
{
	rotate(stack1, 0);
	rotate(stack2, 0);
	print_move("rr", 0);
}

void	rev_rotate_both(stack_list **stack1, stack_list **stack2)
{
	rev_rotate(stack1, 0);
	rev_rotate(stack2, 0);
	print_move("rrr", 0);
}