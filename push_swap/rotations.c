/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:58:14 by rwegat            #+#    #+#             */
/*   Updated: 2024/01/10 16:48:27 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rotate(t_stack_node **head)
{
	t_stack_node	*last_node;
	t_stack_node	*temp;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	last_node = ft_lstlast(*head);
	temp = *head;
	*head = (*head)->next;
	(*head)->previous = NULL;
	last_node->next = temp;
	temp->previous = last_node;
	temp->next = NULL;
}

void	ra(t_stack_node **a)
{
	rotate (a);
	write(1, "ra\n", 3);
}

void	rb(t_stack_node **b)
{
	rotate (b);
	write(1, "rb\n", 3);
}

void	rr(t_stack_node **a, t_stack_node **b)
{
	rotate(a);
	rotate (b);
	write(1, "rr\n", 3);
}
