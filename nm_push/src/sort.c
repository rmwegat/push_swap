/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 09:47:44 by nmihaile          #+#    #+#             */
/*   Updated: 2023/12/19 14:07:22 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

void	sort_by_value(t_lst **lst)
{
	t_lst	*it;
	t_lst	*last;
	t_lst	*tmp;

	it = *lst;
	last = lstlast(*lst);
	while (last && last->prev)
	{
		if (it && it->value > last->value)
		{
			lstswp(lst, it, last);
			tmp = it;
			it = last;
			last = tmp;
		}
		if (it && it->next == last)
		{
			it = *lst;
			last = last->prev;
		}
		else
			it = it->next;
	}
	populate_ids_of_stack(*lst);
}

static void	sort_it_to_stack_a(t_ps *ps)
{
	t_lst	*it;

	while (ps->b)
	{
		topcost(ps->b);
		idcost(ps);
		it = get_cheapest(ps->b);
		move(it, ps);
	}
}

void	finalize_sorting(t_ps *ps)
{
	t_lst			*it;
	unsigned int	pos;
	unsigned int	size;
	int				dir;

	size = lstsize(ps->a);
	it = ps->a;
	pos = 0;
	dir = 1;
	while (it->id > 0)
	{
		pos++;
		it = it->next;
	}
	if (pos <= size / 2)
		dir = -1;
	while (ps->a && ps->a->id)
	{
		if (dir == 1)
			rra(ps, 1);
		else
			ra(ps, 1);
	}
}

void	sort3(t_ps *ps)
{
	if (lstsize(ps->a) == 3)
	{
		if (ps->a->value < ps->a->next->value
			&& ps->a->value > ps->a->next->next->value)
		{
			rra(ps, 1);
			return ;
		}
		if (ps->a->value > ps->a->next->value
			&& ps->a->value > ps->a->next->next->value)
			ra(ps, 1);
		if (ps->a->next->value > ps->a->next->next->value)
		{
			rra(ps, 1);
			sa(ps, 1);
		}
		else if (ps->a->value > ps->a->next->value)
			sa(ps, 1);
	}
	else if (lstsize(ps->a) == 2)
		if (ps->a->value > ps->a->next->value)
			sa(ps, 1);
}

void	sort(t_ps *ps)
{
	pre_sort_to_stack_b(ps);
	sort3(ps);
	sort_it_to_stack_a(ps);
	finalize_sorting(ps);
}
