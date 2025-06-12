/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaparon <rpaparon@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 15:07:23 by rpaparon          #+#    #+#             */
/*   Updated: 2025/06/12 03:33:49 by rpaparon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	push_stack(t_stack *a, int nb)
{
	t_node	*new;
	t_node	*last;

	new = malloc(sizeof(t_node));
	if (!new)
		ft_putstr_fd("Error malloc\n", 2);
	new->value = nb;
	new->index = 0;
	new->next = NULL;
	if (!a->top)
		a->top = new;
	else
	{
		last = a->top;
		while (last->next)
			last = last->next;
		last->next = new;
	}
	a->size++;
}

int	is_duplicate(t_stack *a, int nb)
{
	t_node	*current;

	current = a->top;
	while (current)
	{
		if (current->value == nb)
			return (1);
		current = current->next;
	}
	return (0);
}

int	is_int_range(char *str)
{
	long	n;

	n = ft_atol(str);
	return (n >= INT_MIN && n <= INT_MAX);
}

int	is_valid_number(char *str)
{
	if (!str || !*str)
		return (0);
	if ((*str == '+' || *str == '-') && !str[1])
		return (0);
	if (*str == '+' || *str == '-')
		str++;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

void	parse_args(t_stack *stack_a, int argc, char **argv)
{
	int		i;
	int		j;
	char	**nums;
	long	value;

	i = 1;
	while (i < argc)
	{
		nums = ft_split(argv[i], ' ');
		if (!nums || !nums[0])
			ft_error(stack_a, nums);
		j = 0;
		while (nums[j])
		{
			if (!is_valid_number(nums[j]) || !is_int_range(nums[j]))
				ft_error(stack_a, nums);
			value = ft_atol(nums[j]);
			if (is_duplicate(stack_a, value))
				ft_error(stack_a, nums);
			push_stack(stack_a, value);
			j++;
		}
		free_split(nums);
		i++;
	}
}
