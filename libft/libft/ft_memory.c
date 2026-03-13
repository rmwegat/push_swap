/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmwegat <rmwegat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 15:00:00 by rmwegat           #+#    #+#             */
/*   Updated: 2026/03/13 15:00:00 by rmwegat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*g_alloc_list;

void	*ft_malloc(size_t size)
{
	void	*ptr;
	t_list	*new_node;

	ptr = malloc(size);
	if (!ptr)
		return (NULL);
	new_node = ft_lstnew(ptr);
	if (!new_node)
	{
		free(ptr);
		return (NULL);
	}
	ft_lstadd_front(&g_alloc_list, new_node);
	return (ptr);
}

void	ft_free_all(void)
{
	t_list	*current;
	t_list	*next;

	current = g_alloc_list;
	while (current)
	{
		next = current->next;
		free(current->content);
		free(current);
		current = next;
	}
	g_alloc_list = NULL;
}
