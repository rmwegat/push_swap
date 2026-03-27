/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 15:00:00 by rmwegat           #+#    #+#             */
/*   Updated: 2026/03/19 16:26:29 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_malloc(size_t size, t_list **alloc_list)
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
	ft_lstadd_front(alloc_list, new_node);
	return (ptr);
}

void	ft_free_all(t_list **alloc_list)
{
	t_list	*current;
	t_list	*next;

	if (!alloc_list || !*alloc_list)
		return ;
	current = *alloc_list;
	while (current)
	{
		next = current->next;
		free(current->content);
		free(current);
		current = next;
	}
	*alloc_list = NULL;
}
