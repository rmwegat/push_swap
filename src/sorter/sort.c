/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 16:24:19 by rwegat            #+#    #+#             */
/*   Updated: 2026/03/27 13:35:44 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **a)
{
	t_stack	*highest_node;
	t_stack	*current;

	highest_node = *a;
	current = *a;
	while (current)
	{
		if (current->value > highest_node->value)
			highest_node = current;
		current = current->next;
	}
	if (*a == highest_node)
		ra(a);
	else if ((*a)->next == highest_node)
		rra(a);
	if ((*a)->value > (*a)->next->value)
		sa(a);
}

static void	sort_four(t_stack **a, t_stack **b)
{
	if (is_sorted(*a))
		return ;
	while ((*a)->index != 0)
	{
		ra(a);
	}
	pb(a, b);
	sort_three(a);
	pa(a, b);
}

static void	sort_five(t_stack **a, t_stack **b)
{
	while ((*a)->index != 0)
	{
		ra(a);
	}
	pb(a, b);
	while ((*a)->index != 1)
	{
		ra(a);
	}
	pb(a, b);
	sort_three(a);
	pa(a, b);
	pa(a, b);
}

void	sort_stack(t_stack **a, t_stack **b)
{
	int	size;

	size = get_stack_size(*a);
	if (size == 2)
		sa(a);
	else if (size == 3)
		sort_three(a);
	else if (size == 4)
		sort_four(a, b);
	else if (size == 5)
		sort_five(a, b);
	else
		case_sort(a, b);
}
