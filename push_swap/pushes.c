/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:04:28 by rwegat            #+#    #+#             */
/*   Updated: 2024/01/10 16:18:23 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	push(t_stack_node **src, t_stack_node **dest)
{
	t_stack_node	*temp;

	if (*src == NULL)
		return ;
	temp = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->previous = NULL;
	temp->previous = NULL;
	if (*dest == NULL)
	{
		*dest = temp;
		temp->next = NULL;
	}
	else
	{
		temp->next = *dest;
		temp->next->previous = temp;
		*dest = temp;
	}
}

void	p_to_a(t_stack_node **a, t_stack_node **b)
{
	push(b, a);
	write (1, "pa\n", 3);
}

void	p_to_b(t_stack_node **a, t_stack_node **b)
{
	push(a, b);
	write (1, "pa\n", 3);
}
