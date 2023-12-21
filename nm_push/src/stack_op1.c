/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 10:59:13 by nmihaile          #+#    #+#             */
/*   Updated: 2023/12/19 14:08:13 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

void	sa(t_ps *ps, char print)
{
	if (ps->a == NULL || ps->a->next == NULL)
		return ;
	lstswp(&ps->a, ps->a, ps->a->next);
	if (print)
		ft_printf("sa\n");
}

void	sb(t_ps *ps, char print)
{
	if (ps->b == NULL || ps->b->next == NULL)
		return ;
	lstswp(&ps->b, ps->b, ps->b->next);
	if (print)
		ft_printf("sb\n");
}

void	ss(t_ps *ps, char print)
{
	sa(ps, 0);
	sb(ps, 0);
	if (print)
		ft_printf("ss\n");
}

void	pa(t_ps *ps, char print)
{
	t_lst	*lst;

	if (ps->b == NULL)
		return ;
	lst = ps->b;
	ps->b = ps->b->next;
	if (ps->b)
		ps->b->prev = NULL;
	lstadd_front(&ps->a, lst);
	if (print)
		ft_printf("pa\n");
}

void	pb(t_ps *ps, char print)
{
	t_lst	*lst;

	if (ps->a == NULL)
		return ;
	lst = ps->a;
	ps->a = ps->a->next;
	if (ps->a)
		ps->a->prev = NULL;
	lstadd_front(&ps->b, lst);
	if (print)
		ft_printf("pb\n");
}
