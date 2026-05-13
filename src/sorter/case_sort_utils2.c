/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_sort_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 08:50:25 by rwegat            #+#    #+#             */
/*   Updated: 2026/05/13 13:12:36 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_cost_b(t_stack *b, int value)
{
	int	size_b;
	int	pos_b;

	size_b = get_stack_size(b);
	pos_b = get_index_in_stack(b, value);
	if (pos_b > size_b / 2)
		return ((size_b - pos_b) * -1);
	return (pos_b);
}

int	get_total_cost(int cost_a, int cost_b)
{
	if (cost_a > 0 && cost_b > 0)
	{
		if (cost_a > cost_b)
			return (cost_a);
		return (cost_b);
	}
	else if (cost_a < 0 && cost_b < 0)
	{
		if (absolute_value(cost_a) > absolute_value(cost_b))
			return (absolute_value(cost_a));
		return (absolute_value(cost_b));
	}
	return (absolute_value(cost_a) + absolute_value(cost_b));
}

t_stack	*get_cheapest_b(t_stack **a, t_stack **b)
{
	t_stack	*curr;
	t_stack	*cheapest;
	int		costs[2];
	int		min_cost;

	curr = *b;
	cheapest = *b;
	min_cost = INT_MAX;
	while (curr)
	{
		costs[0] = get_cost_a(*a, curr->value);
		costs[1] = get_cost_b(*b, curr->value);
		if (get_total_cost(costs[0], costs[1]) < min_cost)
		{
			min_cost = get_total_cost(costs[0], costs[1]);
			cheapest = curr;
		}
		curr = curr->next;
	}
	return (cheapest);
}

void	execute_moves(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
	while (cost_a > 0 && cost_b > 0)
	{
		rr(a, b);
		cost_a--;
		cost_b--;
	}
	while (cost_a < 0 && cost_b < 0)
	{
		rrr(a, b);
		cost_a++;
		cost_b++;
	}
	while (cost_a > 0 && cost_a--)
		ra(a);
	while (cost_a < 0 && cost_a++)
		rra(a);
	while (cost_b > 0 && cost_b--)
		rb(b);
	while (cost_b < 0 && cost_b++)
		rrb(b);
}

void	free_stuff(char **args)
{
	int	j;

	j = 0;
	while (args[j])
		free(args[j++]);
	free(args);
}
