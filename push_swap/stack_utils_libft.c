/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:33:57 by rwegat            #+#    #+#             */
/*   Updated: 2024/01/12 12:59:08 by rwegat           ###   ########.fr       */
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

t_stack_node	*ft_lstnew(void *value)
{
	t_stack_node	*new;

	new = (t_stack_node *)malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new -> value = value;
	new -> next = (NULL);
	return (new);
}

int	ft_lstsize(t_stack_node *lst)
{
	while (lst != NULL)
		return (1 + ft_lstsize(lst->next));
	return (0);
}

void	ft_lstadd_back(t_stack_node **lst, t_stack_node *new)
{
	t_stack_node	*current;

	current = *lst;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	while (current -> next != NULL)
	{
		current = current -> next;
	}
	current -> next = new;
}

void	ft_lstadd_front(t_stack_node **lst, t_stack_node *new)
{
	if (new)
	{
		new->next = *lst;
		*lst = new;
	}
}
