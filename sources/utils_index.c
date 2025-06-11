/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_index.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaparon <rpaparon@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 12:59:39 by rpaparon          #+#    #+#             */
/*   Updated: 2025/06/11 13:14:42 by rpaparon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	move_index_to_top(t_stack *a, int index)
{
	t_node	*current;
	int		pos;
	int		size;

	current = a->top;
	pos = 0;
	size = a->size;
	while (current && current->index != index)
	{
		pos++;
		current = current->next;
	}
	if (!current)
		return ;
	if (pos <= size / 2)
		while (a->top->index != index)
			ra(a);
	else
		while (a->top->index != index)
			rra(a);
}

void	push_min_to_b(t_stack *a, t_stack *b, int count)
{
	int		i;
	int		min_index;
	t_node	*current;

	i = 0;
	while (i < count)
	{
		current = a->top;
		min_index = current->index;
		while (current)
		{
			if (current->index < min_index)
				min_index = current->index;
			current = current->next;
		}
		move_index_to_top(a, min_index);
		pb(a, b);
		i++;
	}
}

