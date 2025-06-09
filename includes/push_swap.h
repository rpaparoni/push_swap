/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaparon <rpaparon@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 15:26:45 by rpaparon          #+#    #+#             */
/*   Updated: 2025/06/09 17:31:10 by rpaparon         ###   ########.fr       */
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
void	parse_args(t_stack *stack_a, int argc, char **argv);
void	push_stack(t_stack *a, int nb);
void    free_split(char **split);
void	free_stack(t_stack *stack);
void	init_stack(t_stack *stack);
void	assign_index(t_stack *stack);
void	sort_array(int *arr, int size);
void	assign_indices_to_stack(t_stack *stack, int *sorted);
void	sort_two(t_stack *stack_a);
void	sort_three(t_stack *stack_a);
void	sort_four(t_stack *stack_a, t_stack *stack_b);
void	sort_five(t_stack *stack_a, t_stack *stack_b);
void	sort_controller(t_stack *stack_a, t_stack *stack_b);
void	move_index_to_top(t_stack *stack_a, int index);
void	k_sort(t_stack *stack_a, t_stack *stack_b);
long    ft_atol(const char *str);

//moves
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);

#endif