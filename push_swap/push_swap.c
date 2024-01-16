/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:15:33 by rwegat            #+#    #+#             */
/*   Updated: 2024/01/16 20:55:51 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int argc, char	*argv[])
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (2 == argc)
		argv = ft_split(argv[1], ' ');
	stack_init(&a);
	if (!is_sorted(a))
	{
		if (stacklen(a) == 2)
			sa(&a);
		else if (stacklen(a) == 3)
			sort_3(&a);
		else
			push_swap(&a, &b);
	}
	free_stack(&a);
}

void	sort_3(t_stack_node **a)
{
	t_stack_node	*highest;

	highest = find_highest(*a);
	if (highest == *a)
		ra(a);
	else if ((*a)->next == highest)
		rra(a);
	if ((*a)->value > (*a)->next->value)
		sa(a);
}

