/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_fn.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmughedd <mmughedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:26:29 by mmughedd          #+#    #+#             */
/*   Updated: 2023/12/26 14:04:01 by mmughedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

stack_list	*create_node(char *value, int index)
{
	stack_list	*new_node;

	new_node = malloc(sizeof(stack_list));
	if (!new_node)
		return (NULL);
	new_node->value = (int)atoi(value);
	new_node->index = index;
	new_node->next = NULL;
	return (new_node);
}

void	init_stack(stack_list **stack_a, char **args, int i)
{
	int			j;
	stack_list	*node;

	j = 0;
	*stack_a = create_node(args[i], j++);
	if (!*stack_a)
		return ;
	node = *stack_a;
	while (args[++i])
	{
		node->next =  create_node(args[i], j++);
		node = node->next;
	}
}

void	create_stack(stack_list **stack_a, int argc, char **argv)
{
	char	**args;
	int		i;

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	init_stack(stack_a, args, i);
}

void	swap(stack_list **stack)
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
}

void	push(stack_list **stack1, stack_list **stack2)
{
	stack_list	*temp;

	if (!*stack1)
		return ;
	temp = *stack1;
	if ((*stack1)->next)
		*stack1 = (*stack1)->next;
	else
		*stack1 = NULL;
	temp->next = *stack2;
	*stack2 = temp;
}
//index function
// void	rotate(stack_list **stack)
// {
// 	stack_list	*head;
// 	stack_list	*last;
// 	stack_list	*temp;
// 	int	len;

// 	len = stack_len(*stack);
// 	head = *stack;
// 	last = find_node(*stack, len - 1);
// 	if (!head || !last || head == last)
// 		return ;
// 	temp = *stack;
// 	*stack = head->next;
// 	last->next = temp;
// 	temp->next = NULL;
// }

// void	rev_rotate(stack_list **stack)
// {
// 	stack_list	*second_last;
// 	stack_list	*last;
// 	stack_list	*temp;
// 	int	len;

// 	second_last = find_node(*stack, len - 2);
// 	last = find_node(*stack, len - 1);
// 	if (!second_last || !last || second_last == last)
// 		return ;
// 	temp = *stack;
// 	*stack = last;
// 	(*stack)->next = temp;
// 	second_last->next = NULL;
// }

void	rotate(stack_list **stack)
{
	stack_list	*head;
	stack_list	*last;
	stack_list	*temp;
	int	len;

	head = *stack;
	len = stack_len(*stack);
	last = find_last_node(*stack);
	if (!head || !last || head == last)
		return ;
	temp = *stack;
	*stack = head->next;
	last->next = temp;
	temp->next = NULL;
	change_index(*stack, '-');
	last->index = len - 1;
}

void	rev_rotate(stack_list **stack)
{
	stack_list	*second_last;
	stack_list	*last;
	stack_list	*temp;
	int	len;

	len = stack_len(*stack);
	second_last = find_second_last_node(*stack);
	last = find_last_node(*stack);
	if (!second_last || !last || second_last == last)
		return ;
	temp = *stack;
	*stack = last;
	(*stack)->next = temp;
	second_last->next = NULL;

}