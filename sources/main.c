/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaparon <rpaparon@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 15:26:57 by rpaparon          #+#    #+#             */
/*   Updated: 2025/06/12 03:33:38 by rpaparon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	stack_a;
	t_stack	stack_b;

	init_stack(&stack_a);
	init_stack(&stack_b);
	if (argc == 1)
		return (0);
	parse_args(&stack_a, argc, argv);
	assign_index(&stack_a);
	sort_controller(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
