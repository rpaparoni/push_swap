/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaparon <rpaparon@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 17:15:25 by rpaparon          #+#    #+#             */
/*   Updated: 2025/06/11 16:56:20 by rpaparon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	k_sort(t_stack *a, t_stack *b)
{
	int	range;

	range = ft_sqrt(a->size) * 14 / 10;
	ksort_push_to_b(a, b, range);
	ksort_push_back_to_a(a, b);
}

static void	push_and_reset(t_stack *a, t_stack *b, int *i, int *rotated)
{
	pb(a, b);
	(*i)++;
	*rotated = 0;
}

static void	push_rotate_and_reset(t_stack *a, t_stack *b, int *i, int *rotated)
{
	pb(a, b);
	rb(b);
	(*i)++;
	*rotated = 0;
}

void	ksort_push_to_b(t_stack *a, t_stack *b, int range)
{
	int	i;
	int	rotated;
	int	size;

	i = 0;
	size = a->size;
	rotated = 0;
	while (a->top)
	{
		if (a->top->index <= i)
			push_and_reset(a, b, &i, &rotated);
		else if (a->top->index <= i + range)
			push_rotate_and_reset(a, b, &i, &rotated);
		else
		{
			ra(a);
			rotated++;
		}
		if (rotated >= a->size)
		{
			i++;
			rotated = 0;
		}
	}
}

void	ksort_push_back_to_a(t_stack *a, t_stack *b)
{
	int	target;

	target = b->size - 1;
	while (b->top)
	{
		int	pos = 0;
		t_node *current = b->top;

		while (current && current->index != target)
		{
			pos++;
			current = current->next;
		}
		if (pos <= b->size / 2)
			while (b->top->index != target)
				rb(b);
		else
			while (b->top->index != target)
				rrb(b);
		pa(a, b);
		target--;
	}
}
