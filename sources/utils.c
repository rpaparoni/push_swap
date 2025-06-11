/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaparon <rpaparon@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 12:45:39 by rpaparon          #+#    #+#             */
/*   Updated: 2025/06/11 16:44:27 by rpaparon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	ft_sqrt(int n)
{
	int	i;

	i = 1;
	while (i * i <= n)
		i++;
	return (i - 1);
}

void	ft_error(t_stack *stack_a, char **nums)
{
	if (nums)
		free_split(nums);
	if (stack_a)
		free_stack(stack_a);
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}
