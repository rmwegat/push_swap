/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_logic.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 19:45:35 by rwegat            #+#    #+#             */
/*   Updated: 2024/01/16 20:44:35 by rwegat           ###   ########.fr       */
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
			if (current_node->value > b->value && current_node < best_matching_value)
			{
				best_matching_value = current_node->value;
				target_node = current_node;
			}
			current_node = current_node->next;
		}
		if (best_matching_value == LONG_MAX)
			b->target_node = find_lowest(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}
void	give_current_position(t_stack_node *stack)
{
	int	i;
	int	center;

	i = 0;
	if (!stack)
		return ;
	center = get_stack_len(stack) / 2;
	while (stack)
	{
		stack->current_position = i;
		if (i <= center)
			stack->above_middle = true;
		else if (i >= center)
			stack->above_middle = false;
		stack = stack->next;
		i++;
	}
}

void	set_push_price(t_stack_node *a, t_stack_node *b)
{
	int	stacklen_a;
	int stacklen_b;

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

t_stack_node	*set_cheapest(t_stack_node *stack)
{
	t_stack_node	*cheapest;

	cheapest = stack;
	while (stack)
	{
		if (stack->push_price < cheapest->push_price)
			cheapest = stack;
		stack = stack->next;
	}
	return (cheapest);
}

void nodes_init(t_stack_node *a, t_stack_node *b)
{
	give_current_position(a);
	give_current_position(b);
	set_target_node(a, b);
	set_push_price(a, b);
	set_cheapest;
}

