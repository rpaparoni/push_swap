/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaparon <rpaparon@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 17:15:25 by rpaparon          #+#    #+#             */
/*   Updated: 2025/06/16 13:50:15 by rpaparon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	k_sort(t_stack *a, t_stack *b)
{
	int	range;
	int	size;

	size = a->size;
	range = ft_sqrt(size) * 14 / 10;
	ksort_push_to_b(a, b, range);
	ksort_push_back_to_a(a, b);
}

void	ksort_push_to_b(t_stack *a, t_stack *b, int range)
{
	int	i;
	int	size;

	i = 0;
	size = a->size;
	while (a->top)
	{
		if (a->top->index <= i)
		{
			pb(a, b);
			i++;
		}
		else if (a->top->index <= i + range)
		{
			pb(a, b);
			rb(b);
			i++;
		}
		else
			ra(a);
	}
}

void	ksort_push_back_to_a(t_stack *a, t_stack *b)
{
	int		target;
	int		pos;
	t_node	*current;

	target = b->size - 1;
	while (b->top)
	{
		pos = 0;
		current = b->top;
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
