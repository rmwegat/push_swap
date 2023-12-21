/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utls3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 13:27:48 by nmihaile          #+#    #+#             */
/*   Updated: 2023/12/19 14:08:34 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

// is adjacent
int	lst_isadj(t_lst *a, t_lst *b)
{
	return (((a->next == b && b->prev == a)
			|| (a->prev == b && b->next == a)));
}

void	lst_updadj(t_lst *lst)
{
	if (lst->prev)
		lst->prev->next = lst;
	if (lst->next)
		lst->next->prev = lst;
}

void	lstset_pevnext(t_lst *lst, t_lst *p, t_lst *n)
{
	lst->prev = p;
	lst->next = n;
}

void	swaplstptrs(t_lst **a, t_lst **b)
{
	t_lst	*buf;

	buf = *a;
	*a = *b;
	*b = buf;
}
