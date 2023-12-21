/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:29:10 by nmihaile          #+#    #+#             */
/*   Updated: 2023/12/19 14:07:30 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

static int	calc_dir(t_lst *it, t_lst *st)
{
	unsigned int	size;
	unsigned int	p;

	size = 0;
	p = 0;
	while (st)
	{
		if (st == it)
			p = size;
		size++;
		st = st->next;
	}
	if (p > size / 2)
		return (1);
	return (-1);
}

void	update_target(t_lst *ait, t_lst *bit, t_lst **target)
{
	if (ait->id > bit->id)
	{
		if (*target == NULL)
			*target = ait;
		else if ((*target)->id > ait->id || (*target)->id < bit->id)
			*target = ait;
	}
}

void	settargets(t_ps *ps)
{
	t_lst			*bit;
	t_lst			*ait;
	t_lst			*target;
	unsigned int	size;

	size = lstsize(ps->a);
	bit = ps->b;
	while (bit)
	{
		ait = ps->a;
		target = ait;
		while (ait)
		{
			update_target(ait, bit, &target);
			ait = ait->next;
		}
		if (target && target->id < bit->id)
			target = get_smalestid(ps->a);
		bit->target = target;
		bit->td = calc_dir(target, ps->a);
		bit = bit->next;
	}
}
