/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmughedd <mmughedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:23:54 by mmughedd          #+#    #+#             */
/*   Updated: 2024/01/03 14:33:35 by mmughedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	int	len;

	len = stack_len(*stack_a);
	if (len <= 5)
		solve_small(stack_a, stack_b, len);
	else
		solve_big(stack_a, stack_b, len);
}

void	loop(t_stack *a) //TODO: to delete before submitting
{
	while (a)
	{
		printf("index: %i, value: %i\n", a->index, a->value);
		a = a->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (!check_args(argc, argv))
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	create_stack(&stack_a, argc, argv);
	if (!is_ascending(&stack_a))
		push_swap(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
