/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmwegat <rmwegat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 10:00:00 by rwegat            #+#    #+#             */
/*   Updated: 2026/05/12 17:51:50 by rmwegat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	get_max_val(t_stack *stack)
{
	long	max;

	max = LONG_MIN;
	while (stack)
	{
		if (stack->value > max)
			max = stack->value;
		stack = stack->next;
	}
	return (max);
}

static void	push_chunk(t_stack **a, t_stack **b, long limit)
{
	int	size;
	int	i;

	size = get_stack_size(*a);
	i = 0;
	while (i < size && get_stack_size(*a) > 3)
	{
		if ((*a)->value <= limit)
			pb(a, b);
		else
			ra(a);
		i++;
	}
}

static void	push_to_b(t_stack **a, t_stack **b)
{
	int		chunks;
	int		curr;
	long	min;
	long	step;

	chunks = 6;
	if (get_stack_size(*a) <= 100)
		chunks = 3;
	min = get_min_node(*a)->value;
	step = (get_max_val(*a) - min) / chunks;
	curr = 1;
	while (curr <= chunks)
	{
		push_chunk(a, b, min + (step * curr));
		curr++;
	}
	while (get_stack_size(*a) > 3)
		pb(a, b);
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
