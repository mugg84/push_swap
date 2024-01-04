/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmughedd <mmughedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:23:54 by mmughedd          #+#    #+#             */
/*   Updated: 2024/01/04 14:16:27 by mmughedd         ###   ########.fr       */
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

void	loop(t_stack *a, t_stack *b) //TODO: to delete before submitting
{
	printf("stack_a\n");
	while (a)
	{
		printf("index: %i, value: %i\n", a->index, a->value);
		a = a->next;
	}
	printf("stack_b\n");
	while (b)
	{
		printf("index: %i, value: %i\n", b->index, b->value);
		b = b->next;
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
