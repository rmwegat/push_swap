/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 18:55:40 by nmihaile          #+#    #+#             */
/*   Updated: 2023/12/19 14:07:26 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

static void	finalize_pre_sort(t_ps *ps)
{
	t_lst	*it;

	it = ps->a;
	while (!issizeof3(ps->a))
	{
		it = it->next;
		pb(ps, 1);
		if (ps->b->id >= ps->size / 2 && ps->a && ps->b->next
			&& ps->b->next->id < ps->size / 2)
			rb(ps, 1);
	}
}

void	pre_sort_to_stack_b(t_ps *ps)
{
	t_lst			*it;
	unsigned int	i;

	it = ps->a;
	i = ps->size;
	while (i > 3)
	{
		it = it->next;
		if (ps->a->id < ps->size * 0.75)
		{
			pb(ps, 1);
			if (ps->b->id >= ps->size / 2 && ps->a && ps->b->next
				&& ps->b->next->id < ps->size / 2)
				rb(ps, 1);
		}
		else
			ra(ps, 1);
		i--;
	}
	finalize_pre_sort(ps);
}
