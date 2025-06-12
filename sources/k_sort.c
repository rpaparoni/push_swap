/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaparon <rpaparon@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 17:15:25 by rpaparon          #+#    #+#             */
/*   Updated: 2025/06/12 03:17:59 by rpaparon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	find_next_in_range(t_stack *a, int max)
{
	int		pos;
	t_node	*tmp;

	pos = 0;
	tmp = a->top;
	while (tmp)
	{
		if (tmp->index <= max)
			return (pos);
		pos++;
		tmp = tmp->next;
	}
	return (-1);
}

static void	rotate_and_push(t_stack *a, t_stack *b, int *i)
{
	if (a->top->index <= *i)
	{
		pb(a, b);
		rb(b);
		(*i)++;
	}
	else
		pb(a, b);
}

static void	move_chunk_to_b(t_stack *a, t_stack *b, int chunk_size)
{
	int		i;
	int		pos;

	i = 0;
	while (a->size > 0)
	{
		pos = find_next_in_range(a, i + chunk_size);
		if (pos == -1)
		{
			i += chunk_size;
			continue ;
		}
		if (pos <= a->size / 2)
			while (pos-- > 0)
				ra(a);
		else
			while (pos++ < a->size)
				rra(a);
		rotate_and_push(a, b, &i);
	}
}

static void	push_back_to_a(t_stack *a, t_stack *b)
{
	int		max;
	int		pos;
	t_node	*tmp;

	while (b->size > 0)
	{
		max = get_max_index(b);
		pos = 0;
		tmp = b->top;
		while (tmp && tmp->index != max)
		{
			pos++;
			tmp = tmp->next;
		}
		if (pos <= b->size / 2)
			while (b->top->index != max)
				rb(b);
		else
			while (b->top->index != max)
				rrb(b);
		pa(a, b);
	}
}

void	k_sort(t_stack *a, t_stack *b)
{
	int	chunk_size;

	if (a->size <= 100)
		chunk_size = 15;
	else
		chunk_size = 30;
	move_chunk_to_b(a, b, chunk_size);
	push_back_to_a(a, b);
}
