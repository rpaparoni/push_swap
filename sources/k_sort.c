/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaparon <rpaparon@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 17:15:25 by rpaparon          #+#    #+#             */
/*   Updated: 2025/06/11 17:53:54 by rpaparon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

// Encuentra la posición del primer nodo en a con index <= max
int	find_next_in_range(t_stack *a, int max)
{
	int		pos = 0;
	t_node	*tmp = a->top;

	while (tmp)
	{
		if (tmp->index <= max)
			return pos;
		pos++;
		tmp = tmp->next;
	}
	return -1; // no hay elementos en rango
}

void	k_sort(t_stack *a, t_stack *b)
{
	int	chunk_size = (a->size <= 100) ? 15 : 30;
	int	i = 0;

	while (a->size > 0)
	{
		int	pos = find_next_in_range(a, i + chunk_size);

		if (pos == -1)
		{
			i += chunk_size;
			continue;
		}

		// mueve el elemento a top
		if (pos <= a->size / 2)
			while (pos-- > 0)
				ra(a);
		else
			while (pos++ < a->size)
				rra(a);

		// si es el más bajo, rb para dejarlo al fondo
		if (a->top->index <= i)
		{
			pb(a, b);
			rb(b);
			i++;
		}
		else
		{
			pb(a, b);
		}
	}

	// devolver desde b a a
	while (b->size > 0)
	{
		int	max = get_max_index(b);
		int	pos = 0;
		t_node *tmp = b->top;
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


