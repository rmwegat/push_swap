/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   id.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 11:59:13 by nmihaile          #+#    #+#             */
/*   Updated: 2023/12/19 14:07:34 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

void	populate_ids_of_stack(t_lst *stack)
{
	t_lst	*it;

	it = stack;
	it->id = 0;
	while (it)
	{
		if (it->prev)
			it->id = it->prev->id + 1;
		it = it->next;
	}
}

static void	transfere_ids_to_stack_a(t_ps *ps)
{
	t_lst	*a;
	t_lst	*s;

	a = ps->a;
	s = ps->s;
	while (a)
	{
		if (a->value == s->value)
		{
			a->id = s->id;
			a = a->next;
			s = ps->s;
		}
		else
			s = s->next;
	}
}

void	create_ids(t_ps *ps)
{
	t_lst	*n;
	t_lst	*ln;
	t_lst	*it;

	it = ps->a;
	while (it)
	{
		n = lstnew(it->value);
		if (ps->s == NULL)
			ps->s = n;
		else
		{
			ln->next = n;
			n->prev = ln;
		}
		ln = n;
		it = it->next;
	}
	sort_by_value(&ps->s);
	transfere_ids_to_stack_a(ps);
}
