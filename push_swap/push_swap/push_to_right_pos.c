/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_right_pos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:41:49 by rwegat            #+#    #+#             */
/*   Updated: 2024/02/07 17:10:00 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	rotate_both(t_stack_node **a, t_stack_node **b, \
						t_stack_node *node_to_push)
{
	while (*a != node_to_push->target_node && *b != node_to_push)
		rr(a, b);
	set_current_position(*a);
	set_current_position(*b);
}

static void	reverse_rotate_both(t_stack_node **a, \
								t_stack_node **b, t_stack_node *node_to_push)
{
	while (*a != node_to_push->target_node && *b != node_to_push)
		rrr(a, b);
	set_current_position(*a);
	set_current_position(*b);
}

void	finish_rotation(t_stack_node **stack, \
						char stack_name, t_stack_node *node_to_push)
{
	while (*stack != node_to_push)
	{
		if (stack_name == 'a')
		{
			if (node_to_push->above_middle)
				ra(stack);
			else
				rra(stack);
		}
		else if (stack_name == 'b')
		{
			if (node_to_push ->above_middle)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

static void	do_cheapest_push(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*node_to_push;

	node_to_push = get_cheapest(a);
	if (node_to_push->above_middle && node_to_push->target_node->above_middle)
		rotate_both(a, b, node_to_push);
	else if (!(node_to_push->above_middle) \
			&& !(node_to_push->target_node->above_middle))
		reverse_rotate_both(a, b, node_to_push);
	finish_rotation(a, 'a', node_to_push);
	finish_rotation(b, 'b', node_to_push);
	pa(a, b);
}
