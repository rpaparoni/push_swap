/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaparon <rpaparon@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 15:08:37 by rpaparon          #+#    #+#             */
/*   Updated: 2025/06/12 03:44:09 by rpaparon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	sort_controller(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 1)
		return ;
	else if (stack_a->size == 2)
		sort_two(stack_a);
	else if (stack_a->size == 3)
		sort_three(stack_a);
	else if (stack_a->size == 4)
		sort_four(stack_a, stack_b);
	else if (stack_a->size == 5)
		sort_five(stack_a, stack_b);
	else
		k_sort(stack_a, stack_b);
}

void	sort_two(t_stack *stack_a)
{
	if (stack_a->top->index > stack_a->top->next->index)
		sa(stack_a);
}

void	sort_three(t_stack *a)
{
	t_node	*n1;
	t_node	*n2;
	t_node	*n3;

	n1 = a->top;
	n2 = n1->next;
	n3 = n2->next;
	sort_three_cases(a, n1, n2, n3);
}

void	sort_four(t_stack *stack_a, t_stack *stack_b)
{
	push_min_to_b(stack_a, stack_b, 1);
	sort_three(stack_a);
	if (stack_b->top)
		pa(stack_a, stack_b);
}

void	sort_five(t_stack *stack_a, t_stack *stack_b)
{
	push_min_to_b(stack_a, stack_b, 2);
	sort_three(stack_a);
	if (stack_b->top)
		pa(stack_a, stack_b);
	if (stack_b->top)
		pa(stack_a, stack_b);
}
