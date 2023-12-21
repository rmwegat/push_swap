/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:04:57 by nmihaile          #+#    #+#             */
/*   Updated: 2023/12/19 14:08:21 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

static void	rdown(t_lst **lst)
{
	t_lst	*it;

	if (*lst == NULL || (*lst)->next == NULL)
		return ;
	it = lstlast(*lst);
	it->prev->next = NULL;
	lstadd_front(lst, it);
}

void	rra(t_ps *ps, char print)
{
	rdown(&ps->a);
	if (print)
		ft_printf("rra\n");
}

void	rrb(t_ps *ps, char print)
{
	rdown(&ps->b);
	if (print)
		ft_printf("rrb\n");
}

void	rrr(t_ps *ps, char print)
{
	rdown(&ps->a);
	rdown(&ps->b);
	if (print)
		ft_printf("rrr\n");
}
