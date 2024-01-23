/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:15:33 by rwegat            #+#    #+#             */
/*   Updated: 2024/01/23 14:04:44 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	leaks(void)
{
	write(1, '\n', 1);
	system("leaks push_swap");
}

int	main(int argc, char	*argv[])
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	atexit (leaks);
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (2 == argc)
		argv = ft_split(argv[1], ' ');
	init_stack(&a, argv + 1);
	if (!is_sorted(a))
	{
		if (get_stack_len(a) == 2)
			sa(&a);
		else if (get_stack_len(a) == 3)
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

