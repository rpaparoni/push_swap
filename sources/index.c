/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaparon <rpaparon@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 13:01:37 by rpaparon          #+#    #+#             */
/*   Updated: 2025/06/09 13:17:07 by rpaparon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	sort_array(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = -1;
	while (++i < size - 1)
	{
		j = -1;
		while (++j < size - 1 - i)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}

void	assign_indices_to_stack(t_stack *stack, int *sorted)
{
	t_node	*current;
	int		i;

	current = stack->top;
	while (current)
	{
		i = 0;
		while (i < stack->size)
		{
			if (current->value == sorted[i])
			{
				current->index = i;
				break;
			}
			i++;
		}
		current = current->next;
	}
}

void	assign_index(t_stack *stack)
{
	t_node	*current;
	int		*sorted;
	int		i;

	sorted = malloc(sizeof(int) * stack->size);
	if (!sorted)
	ft_putstr_fd("Error index", 2);
	current = stack->top;
	i = 0;
	while (current)
	{
		sorted[i++] = current->value;
		current = current->next;
	}
	sort_array(sorted, stack->size);
	assign_indices_to_stack(stack, sorted);
	free(sorted);
}

