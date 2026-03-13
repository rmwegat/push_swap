/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 15:00:00 by rmwegat           #+#    #+#             */
/*   Updated: 2026/03/13 12:56:27 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft/libft.h"
# include "../libft/ft_printf/ft_printf.h"

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}					t_stack;

// main
void	ft_error(void);

// init
void	init_stack(t_stack **a, int argc, char **argv);

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

// utils
int		is_sorted(t_stack *a);
int		get_stack_size(t_stack *a);
t_stack	*get_stack_bottom(t_stack *a);
t_stack	*get_stack_before_bottom(t_stack *a);
void	assign_index(t_stack *a, int size);

#endif