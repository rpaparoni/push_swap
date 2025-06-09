/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaparon <rpaparon@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:57:09 by rpaparon          #+#    #+#             */
/*   Updated: 2025/06/09 17:01:35 by rpaparon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void    sb(t_stack *stack_b)
{
	t_node	*first;
	t_node	*second;

	if (!stack_b || !stack_b->top || !stack_b->top->next)
		return ;
	first = stack_b->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	stack_b->top = second;
	ft_printf("sb");
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*tmp;

	if (!stack_b || !stack_b->top)
		return ;
	tmp = stack_a->top;
	stack_a->top = stack_a->top->next;
	tmp->next = stack_b->top;
	stack_b->top = tmp;
	stack_b->size++;
        stack_a->size--;
	ft_printf("pb");
}

void	rb(t_stack *stack_b)
{
	t_node	*first;
	t_node	*last;

	if (!stack_b || !stack_b->top || !stack_b->top->next)
		return ;
	first = stack_b->top;
	stack_b->top = first->next;
	first->next = NULL;

	last = stack_b->top;
	while (last->next)
		last = last->next;
	last->next = first;
	ft_printf("rb");
}

void	rrb(t_stack *stack_b)
{
	t_node	*prev;
	t_node	*last;

	if (!stack_b || !stack_b->top || !stack_b->top->next)
		return ;
	prev = NULL;
	last = stack_b->top;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = stack_b->top;
	stack_b->top = last;
	ft_printf("rrb");
}