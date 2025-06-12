/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaparon <rpaparon@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:54:51 by rpaparon          #+#    #+#             */
/*   Updated: 2025/06/12 03:38:53 by rpaparon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	sa(t_stack *stack_a)
{
	t_node	*first;
	t_node	*second;

	if (!stack_a || !stack_a->top || !stack_a->top->next)
		return ;
	first = stack_a->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	stack_a->top = second;
	ft_printf("sa\n");
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*tmp;

	if (!stack_b || !stack_b->top)
		return ;
	tmp = stack_b->top;
	stack_b->top = stack_b->top->next;
	tmp->next = stack_a->top;
	stack_a->top = tmp;
	stack_b->size--;
	stack_a->size++;
	ft_printf("pa\n");
}

void	ra(t_stack *stack_a)
{
	t_node	*first;
	t_node	*last;

	if (!stack_a || !stack_a->top || !stack_a->top->next)
		return ;
	first = stack_a->top;
	stack_a->top = first->next;
	first->next = NULL;
	last = stack_a->top;
	while (last->next)
		last = last->next;
	last->next = first;
	ft_printf("ra\n");
}

void	rra(t_stack *stack_a)
{
	t_node	*prev;
	t_node	*last;

	if (!stack_a || !stack_a->top || !stack_a->top->next)
		return ;
	prev = NULL;
	last = stack_a->top;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = stack_a->top;
	stack_a->top = last;
	ft_printf("rra\n");
}
