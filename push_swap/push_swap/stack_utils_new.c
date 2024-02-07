/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_new.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:30:36 by rwegat            #+#    #+#             */
/*   Updated: 2024/02/07 17:32:25 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_stack_node	*get_highest(t_stack_node *stack)
{
	t_stack_node	*highest;

	highest = stack;
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->value > stack->next->value)
			highest = stack->next;
		stack = stack->next;
	}
	return (highest);
}

t_stack_node	*get_lowest(t_stack_node *stack)
{
	t_stack_node	*highest;

	highest = stack;
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->value < stack->next->value)
			highest = stack->next;
		stack = stack->next;
	}
	return (highest);
}

t_stack_node	*get_cheapest(t_stack_node *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack)
	{
		if (stack->is_cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

bool	is_sorted(t_stack_node *stack)
{
	if (!stack)
		return (true);
	while (stack)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

int	get_stack_len(t_stack_node *stack)
{
	int	length;

	length = 0;
	while (stack)
	{
		length++;
		stack = stack->next;
	}
	return (length);
}
