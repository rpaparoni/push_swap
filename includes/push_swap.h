/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaparon <rpaparon@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 15:26:45 by rpaparon          #+#    #+#             */
/*   Updated: 2025/06/05 18:24:22 by rpaparon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../libft/libft.h"
#include <limits.h>

typedef struct s_node
{
	int		value;
	int		index;
	struct s_node	*next;
}   t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}   t_stack;

int		main(int  argc, char	*argv[]);
int		is_valid_number(char *str);
int		is_int_range(char *str);
int		is_duplicate(t_stack *a, int nb);
void	parse_args(t_stack *a, int argc, char **argv);
void	push_stack(t_stack *a, int nb);
void    free_split(char **split);
void	free_stacks(t_stack **stack);
long    ft_atol(const char *str);

#endif