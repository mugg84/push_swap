/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmughedd <mmughedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:23:54 by mmughedd          #+#    #+#             */
/*   Updated: 2023/12/29 11:17:17 by mmughedd         ###   ########.fr       */
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
	if (!is_ordered(&stack_a))
			solve_stack(&stack_a, &stack_b);
	//loop(stack_a);
	return (0);
}