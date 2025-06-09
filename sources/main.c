/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaparon <rpaparon@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 15:26:57 by rpaparon          #+#    #+#             */
/*   Updated: 2025/06/09 13:15:03 by rpaparon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	print_stack(t_stack *stack, char *name)
{
	t_node	*current;

	ft_printf("Stack %s:\n", name);
	current = stack->top;
	while (current)
	{
		ft_printf("[VAL: %d | IDX: %d]\n", current->value, current->index);
		current = current->next;
	}
	ft_printf("-----\n");
}


int	main(int argc, char *argv[])
{
	t_stack stack_a;
	t_stack stack_b;

	init_stack(&stack_a);
	init_stack(&stack_b);
	if (argc == 1)
		return (0);
	parse_args(&stack_a, argc, argv);
	assign_index(&stack_a);
	//pus_suas
	print_stack(&stack_a, "A");
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}