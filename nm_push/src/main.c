/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:13:19 by nmihaile          #+#    #+#             */
/*   Updated: 2023/12/20 15:27:35 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

static void	free_stacks(t_ps *ps)
{
	if (ps->a)
		clrlst(&ps->a);
	if (ps->b)
		clrlst(&ps->b);
	if (ps->s)
		clrlst(&ps->s);
}

void leaks(void)
{
	ft_printf("######################\n");
	system("leaks push_swap");
}

int	main(int ac, char *av[])
{
	static t_ps	ps;

	// atexit(leaks);
	if (ac > 1)
	{
		if (av[1][0])
		{
			if (load(ac, av, &ps) && is_unique(ps.a))
			{
				if (is_sorted(ps.a) == FALSE)
				{
					create_ids(&ps);
					sort(&ps);
				}
			}
			else
				write(2, "Error\n", 6);
		}
	}
	free_stacks(&ps);
	return (0);
}
