/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaparon <rpaparon@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 15:07:23 by rpaparon          #+#    #+#             */
/*   Updated: 2025/06/05 18:18:55 by rpaparon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	push_stack(t_stack *a, int nb)
{

}

int	is_duplicate(t_stack *a, int nb)
{

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

void	parse_args(t_stack *a, int argc, char **argv)
{
	int	i;
	int	j;
	char	**nums;
	long	value;

	i = 1;
	while (i < argc)
	{
		nums = ft_split(argv[i], ' ');
		if (!nums || !nums[0])
			error();
		j = 0;
		while (nums[j])
		{
			if (!is_valid_number(nums[j]) || !is_int_range(nums[j]))
				error();
			value = ft_atol(nums[j]);
			if (is_duplicate(a, value))
				error();
			push_stack(a, value);
			j++;
		}
		free_split(nums);
		i++;
	}
}