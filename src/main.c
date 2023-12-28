/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmughedd <mmughedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:23:54 by mmughedd          #+#    #+#             */
/*   Updated: 2023/12/26 13:54:20 by mmughedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	solve_stack(stack_list **stack_a, stack_list **stack_b)
{
	int	len;

	len = stack_len(*stack_a);
	if (len <= 5)
		solve_small(stack_a, stack_b, len);
}

void	loop(stack_list *a)
{
	while (a)
	{
		printf("index: %i, value: %i\n", a->index, a->value);
		a = a->next;
	}
}

int	main(int argc, char **argv)
{
	stack_list	*stack_a = {NULL};
	stack_list	*stack_b = {NULL};

	if (!check_args(argc, argv))
		return (0);
	create_stack(&stack_a, argc, argv);
	// change_index(stack_a, '-');
	// while (!is_ordered(&stack_a))
	// 	solve_stack(&stack_a, &stack_b);
	int i = 0;
	//int a = find_smallest_num(stack_a);
	//printf("%i/n", a);
	// push(&stack_a, &stack_b);
	// printf("a_head: %i, b_head: %i\n", stack_a->value, stack_b->value);
	// push(&stack_a, &stack_b);
	// printf("a_head: %i, b_head: %i\n", stack_a->value, stack_b->value);
	// push(&stack_a, &stack_b);
	// printf("a_head: %i, b_head: %i\n", stack_a->value, stack_b->value);
	// push(&stack_a, &stack_b);
	// printf("b_head: %i\n", stack_b->value);
	//printf("in order");
	//free_stack(&stack_a);
	//free_stack(&stack_b);
	// printf("head: %i, last: %i\n", stack_a->value, (find_last_node(stack_a)->value));
	// rotate(&stack_a);
	// printf("head: %i, last: %i\n", stack_a->value, (find_last_node(stack_a)->value));
	// printf("head: %i, last: %i\n", stack_a->value, (find_last_node(stack_a)->value));
	// rev_rotate(&stack_a);
	// printf("head: %i, last: %i\n", stack_a->value, (find_last_node(stack_a)->value));
	while (!is_ordered(&stack_a))
	{
		rotate(&stack_a);
		printf("rotated %d\n", i++);
	}
	loop(stack_a);
	// while (!is_ordered(&stack_a))
	// {
	// 	rev_rotate(&stack_a);
	// 	printf("rotated %d\n", i++);
	// }
	return (0);
}