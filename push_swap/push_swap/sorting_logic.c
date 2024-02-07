/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_logic.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 19:45:35 by rwegat            #+#    #+#             */
/*   Updated: 2024/02/07 18:49:42 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	set_target_node(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_node;
	t_stack_node	*target_node;
	long			best_matching_value;

	while (b)
	{
		best_matching_value = LONG_MAX;
		current_node = a;
		while (current_node)
		{
			if (current_node->value > b->value \
				&& current_node->value < best_matching_value)
			{
				best_matching_value = current_node->value;
				target_node = current_node;
			}
			current_node = current_node->next;
		}
		if (best_matching_value == LONG_MAX)
			b->target_node = get_lowest(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

void	set_current_position(t_stack_node *stack)
{
	int	i;
	int	middle;

	i = 0;
	if (!stack)
		return ;
	middle = get_stack_len(stack) / 2;
	while (stack)
	{
		stack->current_position = i;
		if (i <= middle)
			stack->above_middle = true;
		else if (i >= middle)
			stack->above_middle = false;
		stack = stack->next;
		i++;
	}
}

void	set_push_price(t_stack_node *a, t_stack_node *b)
{
	int	stacklen_a;
	int	stacklen_b;

	stacklen_a = get_stack_len(a);
	stacklen_b = get_stack_len(b);
	while (b)
	{
		b->push_price = b->current_position;
		if (b->above_middle == false)
			b->push_price = stacklen_b - b->current_position;
		if (b->target_node->above_middle)
			b->push_price += b->target_node->current_position;
		else
			b->push_price += stacklen_a - b->target_node->current_position;
		b = b->next;
	}
}

void	set_cheapest(t_stack_node *stack)
{
	t_stack_node	*cheapest;
	long			lowest_price;

	if (!stack)
		return ;
	lowest_price = LONG_MAX;
	while (stack)
	{
		if (stack->push_price < lowest_price)
		{
			lowest_price = stack->push_price;
			cheapest = stack;
		}
		stack = stack->next;
	}
	cheapest->is_cheapest = true;
}

void	init_nodes(t_stack_node *a, t_stack_node *b)
{
	set_current_position(a);
	set_current_position(b);
	set_target_node(a, b);
	set_push_price(a, b);
	set_cheapest(b);
}
