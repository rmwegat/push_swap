/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 15:33:42 by nmihaile          #+#    #+#             */
/*   Updated: 2023/12/19 14:09:16 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

unsigned int	steps_to_move_up(int *dir, t_lst *it, t_lst *st)
{
	unsigned int	pos;
	unsigned int	size;

	if (st == NULL || it == NULL)
		return (0);
	size = 0;
	*dir = -1;
	while (st)
	{
		size++;
		if (it == st)
			pos = size;
		st = st->next;
	}
	if (pos > size / 2 && pos > 2)
	{
		*dir = 1;
		return (size - pos + 1);
	}
	return (pos - 1);
}

void	rotate_stacks(int ad, int bd, t_ps *ps)
{
	if (ad == bd && ad != 0 && bd != 0)
	{
		if (ad > 0)
			rrr(ps, 1);
		else
			rr(ps, 1);
		return ;
	}
	if (bd > 0)
		rrb(ps, 1);
	else if (bd < 0)
		rb(ps, 1);
	if (ad > 0)
		rra(ps, 1);
	else if (ad < 0)
		ra(ps, 1);
}

void	move(t_lst *it, t_ps *ps)
{
	int	ad;
	int	bd;

	if (it == NULL || ps->b == NULL)
		return ;
	ad = 0;
	bd = 0;
	if (ps->a != it->target)
	{
		if (it->td > 0)
			ad = 1;
		else
			ad = -1;
	}
	if (ps->b != it)
		bd = it->dir;
	while (ps->a != it->target || ps->b != it)
	{
		if (ps->a == it->target)
			ad = 0;
		if (ps->b == it)
			bd = 0;
		rotate_stacks(ad, bd, ps);
	}
	pa(ps, 1);
}
