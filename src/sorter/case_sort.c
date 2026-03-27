/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 10:00:00 by rwegat            #+#    #+#             */
/*   Updated: 2026/03/27 10:00:00 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

static void	push_to_b(t_stack **a, t_stack **b)
{
	int	size;
	int	pushed;
	int	i;

	size = get_stack_size(*a);
	pushed = 0;
	i = 0;
	while (size > 6 && i < size && pushed < size / 2)
	{
		if ((*a)->index <= size / 2)
		{
			pb(a, b);
			pushed++;
		}
		else
			ra(a);
		i++;
	}
	while (size - pushed > 3)
	{
		pb(a, b);
		pushed++;
	}
}

static void	final_rotation(t_stack **a)
{
	int	pos;
	int	size;

	pos = get_index_in_stack(*a, get_min_node(*a)->value);
	size = get_stack_size(*a);
	if (pos > size / 2)
	{
		while (pos < size)
		{
			rra(a);
			pos++;
		}
	}
	else
	{
		while (pos > 0)
		{
			ra(a);
			pos--;
		}
	}
}

void	case_sort(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;
	int		cost_a;
	int		cost_b;

	push_to_b(a, b);
	sort_three(a);
	while (*b)
	{
		cheapest = get_cheapest_b(a, b);
		cost_a = get_cost_a(*a, cheapest->value);
		cost_b = get_cost_b(*b, cheapest->value);
		execute_moves(a, b, cost_a, cost_b);
		pa(a, b);
	}
	final_rotation(a);
}
