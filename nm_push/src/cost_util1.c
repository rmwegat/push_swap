/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_util1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:24:50 by nmihaile          #+#    #+#             */
/*   Updated: 2023/12/19 14:07:38 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

void	topcost(t_lst *lst)
{
	size_t	size;
	size_t	c;

	size = lstsize(lst);
	c = 0;
	while (lst)
	{
		if (c < size / 2)
		{
			lst->cost = c;
			lst->dir = -1;
		}
		else
		{
			lst->cost = size - size / 2 + ((size / 2 - c) - 1) + 1;
			lst->dir = 1;
		}
		lst = lst->next;
		c++;
	}
}

void	idcost(t_ps *ps)
{
	t_lst	*bit;

	settargets(ps);
	bit = ps->b;
	while (bit)
	{
		bit->cost += steps_to_move_up(&bit->td, bit->target, ps->a);
		bit = bit->next;
	}
}

t_lst	*get_cheapest(t_lst *stack)
{
	t_lst			*lst;
	unsigned int	lc;

	lc = 4294967295;
	while (stack)
	{
		if (stack->cost < lc)
		{
			lst = stack;
			lc = stack->cost;
		}
		stack = stack->next;
	}
	return (lst);
}

t_lst	*get_smalestid(t_lst *stack)
{
	t_lst			*lst;
	unsigned int	lid;

	lid = 4294967295;
	while (stack)
	{
		if (stack->id < lid)
		{
			lst = stack;
			lid = stack->id;
		}
		stack = stack->next;
	}
	return (lst);
}
