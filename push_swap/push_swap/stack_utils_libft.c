/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_libft.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:33:57 by rwegat            #+#    #+#             */
/*   Updated: 2024/01/22 15:56:15 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_stack_node	*ft_lstlast(t_stack_node *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_stack_node **lst, int nbr)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (NULL == lst)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (!node)
		return ;
	node->next = NULL;
	node->value = nbr;
	if (*lst == NULL)
	{
		*lst = node;
		node->previous = NULL;
	}
	else
	{
		last_node = ft_lstlast(*lst);
		last_node->next = node;
		node->previous = last_node;
	}
}

void	ft_lstadd_front(t_stack_node **lst, t_stack_node *new)
{
	if (new)
	{
		new->next = *lst;
		*lst = new;
	}
}
