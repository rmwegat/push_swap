/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:58:56 by rwegat            #+#    #+#             */
/*   Updated: 2024/01/10 16:54:07 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	reverse_rotate(t_stack_node **head)
{
	t_stack_node	*last_node;
	t_stack_node	*temp;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	last_node = ft_lstlast(*head);
	temp = last_node->previous;
	temp->next = NULL;
	last_node->previous = NULL;
	last_node->next = *head;
	(*head)->previous = last_node;
	*head = last_node;
}

void	rra(t_stack_node **a)
{
	reverse_rotate (a);
	write(1, "rra\n", 3);
}

void	rrb(t_stack_node **b)
{
	reverse_rotate (b);
	write(1, "rrb\n", 3);
}

void	rrr(t_stack_node **a, t_stack_node **b)
{
	reverse_rotate(a);
	reverse_rotate (b);
	write(1, "rrr\n", 3);
}
