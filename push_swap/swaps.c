/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:02:55 by rwegat            #+#    #+#             */
/*   Updated: 2024/01/10 16:02:36 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	swap(t_stack_node **head)
{
	t_stack_node	*temp;

	if (*head == NULL || head == NULL || (*head)->next == NULL)
		return ;
	temp = (*head)->next;
	(*head)->next = temp->next;
	(*head)->previous = temp;
	if (temp->next != NULL)
		temp->next->previous = *head;
	temp->next = *head;
	temp->previous = NULL;
	*head = temp;
}

void	sa(t_stack_node **a)
{
	swap(a);
	write (1, "sa\n", 3);
}

void	sb(t_stack_node **b)
{
	swap(b);
	write (1, "sa\n", 3);
}

void	ss(t_stack_node **a, t_stack_node **b)
{
	swap(a);
	swap(b);
	write (1, "ss\n", 3);
}
