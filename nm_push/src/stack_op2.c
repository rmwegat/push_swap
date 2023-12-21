/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:37:45 by nmihaile          #+#    #+#             */
/*   Updated: 2023/12/19 16:04:35 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

static void	rup(t_lst **lst)
{
	t_lst	*it;

	it = *lst;
	if (it->next == NULL)
		return ;
	(*lst) = it->next;
	(*lst)->prev = NULL;
	lstadd_back(lst, it);
}

void	ra(t_ps *ps, char print)
{
	if (ps->a && ps->a->next)
	{
		rup(&ps->a);
		if (print)
			ft_printf("ra\n");
	}
}

void	rb(t_ps *ps, char print)
{
	if (ps->b && ps->b->next)
	{
		rup(&ps->b);
		if (print)
			ft_printf("rb\n");
	}
}

void	rr(t_ps *ps, char print)
{
	if (ps->a && ps->a->next)
		rup(&ps->a);
	if (ps->b && ps->b->next)
		rup(&ps->b);
	if (print)
		ft_printf("rr\n");
}
