/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmughedd <mmughedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:23:54 by mmughedd          #+#    #+#             */
/*   Updated: 2024/01/02 10:05:38 by mmughedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	solve_stack(stack_list **stack_a, stack_list **stack_b)
{
	int	len;

	len = stack_len(*stack_a);
	if (len <= 5)
		solve_small(stack_a, stack_b, len);
	else
		solve_big(stack_a, stack_b, len);
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
	// if (!is_ascending(&stack_a))
	// 		solve_stack(&stack_a, &stack_b);
	// push(&stack_a, &stack_b);
	// push(&stack_a, &stack_b);
	// push(&stack_a, &stack_b);
	// push(&stack_a, &stack_b);
	// push(&stack_a, &stack_b);
	// push(&stack_a, &stack_b);
	// push(&stack_a, &stack_b);
	// push(&stack_a, &stack_b);
	solve_stack(&stack_a, &stack_b);
	//calc_cost(stack_a, stack_b);
	printf("stack_a\n");
	loop(stack_a);
	printf("stack_b\n");
	loop(stack_b);
	return (0);
}