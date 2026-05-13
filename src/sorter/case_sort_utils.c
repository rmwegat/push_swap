/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_sort_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 08:50:17 by rwegat            #+#    #+#             */
/*   Updated: 2026/05/13 08:50:18 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	absolute_value(int i)
{
	if (i < 0)
		return (-i);
	return (i);
}

int	get_index_in_stack(t_stack *stack, int value)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack->value == value)
			return (i);
		stack = stack->next;
		i++;
	}
	return (-1);
}

t_stack	*get_min_node(t_stack *stack)
{
	t_stack	*min_node;
	long	min_val;

	min_val = LONG_MAX;
	min_node = NULL;
	while (stack)
	{
		if (stack->value < min_val)
		{
			min_val = stack->value;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

t_stack	*get_target_in_a(t_stack *a, int value)
{
	t_stack	*current;
	t_stack	*target;
	long	best_match;

	current = a;
	target = NULL;
	best_match = LONG_MAX;
	while (current)
	{
		if (current->value > value && current->value < best_match)
		{
			best_match = current->value;
			target = current;
		}
		current = current->next;
	}
	if (best_match == LONG_MAX)
		return (get_min_node(a));
	return (target);
}

int	get_cost_a(t_stack *a, int value)
{
	int		size_a;
	t_stack	*target_a;
	int		pos_a;

	size_a = get_stack_size(a);
	target_a = get_target_in_a(a, value);
	pos_a = get_index_in_stack(a, target_a->value);
	if (pos_a > size_a / 2)
		return ((size_a - pos_a) * -1);
	return (pos_a);
}
