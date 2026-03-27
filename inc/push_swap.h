/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 16:25:05 by rwegat            #+#    #+#             */
/*   Updated: 2026/03/27 13:45:36 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft/libft.h"
# include "libft/ft_printf/ft_printf.h"

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}					t_stack;

// main
void	ft_error(t_list **alloc_list);

// init
void	init_stack(t_stack **a, int argc, char **argv, t_list **alloc_list);

// operations
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

// sort
void	sort_stack(t_stack **a, t_stack **b);
void	case_sort(t_stack **a, t_stack **b);
void	sort_three(t_stack **a);

// case sort utils
int		absolute_value(int i);
int		get_index_in_stack(t_stack *stack, int value);
t_stack	*get_min_node(t_stack *stack);
t_stack	*get_target_in_a(t_stack *a, int value);
int		get_cost_a(t_stack *a, int value);
int		get_cost_b(t_stack *b, int value);
int		get_total_cost(int cost_a, int cost_b);
t_stack	*get_cheapest_b(t_stack **a, t_stack **b);
void	execute_moves(t_stack **a, t_stack **b, int cost_a, int cost_b);

// utils
int		is_sorted(t_stack *a);
int		get_stack_size(t_stack *a);
t_stack	*get_stack_bottom(t_stack *a);
t_stack	*get_stack_before_bottom(t_stack *a);
void	assign_index(t_stack *a, int size);

#endif