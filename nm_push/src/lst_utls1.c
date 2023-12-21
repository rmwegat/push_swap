/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utls1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 19:08:27 by nmihaile          #+#    #+#             */
/*   Updated: 2023/12/19 14:08:27 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

t_lst	*lstnew(int nb)
{
	t_lst	*lst;

	lst = malloc(1 * sizeof(t_lst));
	if (lst == NULL)
		return (NULL);
	lst->value = nb;
	lst->id = 0;
	lst->cost = 0;
	lst->dir = -1;
	lst->td = -1;
	lst->target = NULL;
	lst->prev = NULL;
	lst->next = NULL;
	return (lst);
}

void	lstadd_front(t_lst **pl, t_lst *lst)
{
	if (*pl == NULL && lst)
	{
		lst->prev = NULL;
		lst->next = NULL;
	}
	else
	{
		lst->prev = NULL;
		lst->next = *pl;
		(*pl)->prev = lst;
	}
	*pl = lst;
}

void	lstadd_back(t_lst **pl, t_lst *new)
{
	t_lst	*buf;

	if (*pl && new)
	{
		buf = *pl;
		while (buf->next)
			buf = buf->next;
		buf->next = new;
		new->prev = buf;
		new->next = NULL;
	}
	else if (*pl == NULL && new)
	{
		*pl = new;
		new->prev = NULL;
		new->next = NULL;
	}
}

void	lstswp(t_lst **head, t_lst *a, t_lst *b)
{
	t_lst	*swaps[4];

	if (b->next == a)
		swaplstptrs(&a, &b);
	swaps[0] = a->prev;
	swaps[1] = a->next;
	swaps[2] = b->prev;
	swaps[3] = b->next;
	if (lst_isadj(a, b))
	{
		lstset_pevnext(a, swaps[1], swaps[3]);
		lstset_pevnext(b, swaps[0], swaps[2]);
	}
	else
	{
		lstset_pevnext(a, swaps[2], swaps[3]);
		lstset_pevnext(b, swaps[0], swaps[1]);
	}
	lst_updadj(a);
	lst_updadj(b);
	if (*head == a)
		*head = b;
	else if (*head == b)
		*head = a;
}
