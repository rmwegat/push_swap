/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees'n'errors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:05:01 by rwegat            #+#    #+#             */
/*   Updated: 2024/02/07 18:31:53 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*temp;
	t_stack_node	*current;
 
	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	*stack = NULL;
}

void free_split(char **argv)
{
	int	i;

	if (!argv || !(*argv))
		return ;
	i = -1;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv[i]);
}

int	check_repetion(t_stack_node *stack, int nbr)
{
	int	times_encountered;
	
	if (!stack)
		return (0);
	times_encountered = 0;
	while (stack)
	{
		if (stack->value == nbr)
			times_encountered++;
		stack = stack->next;
	}
	return (times_encountered);
}
