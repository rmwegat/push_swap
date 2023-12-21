/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utls2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 10:01:19 by nmihaile          #+#    #+#             */
/*   Updated: 2023/12/20 11:19:05 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

size_t	lstsize(t_lst *lst)
{
	size_t	c;

	c = 0;
	while (lst)
	{
		c++;
		lst = lst->next;
	}
	return (c);
}

int	issizeof3(t_lst *lst)
{
	char	c;

	if (lst == NULL)
		return (1);
	c = 1;
	while (lst)
	{
		if (c >= 3 && lst && lst->next)
			return (0);
		c++;
		lst = lst->next;
	}
	return (1);
}

t_lst	*lstlast(t_lst *lst)
{
	t_lst	*it;

	if (lst == NULL)
		return (NULL);
	it = lst;
	while (it->next)
		it = it->next;
	return (it);
}

void	clrlst(t_lst **lst)
{
	t_lst	*b;

	b = *lst;
	while (b)
	{
		*lst = (*lst)->next;
		free(b);
		b = NULL;
		b = *lst;
	}
}
