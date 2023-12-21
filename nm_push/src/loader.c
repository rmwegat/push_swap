/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:56:35 by nmihaile          #+#    #+#             */
/*   Updated: 2023/12/19 14:07:11 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

int	ft_wc(char *s)
{
	int	wc;

	wc = 0;
	while (s && *s)
	{
		s = ft_skipspace(s);
		if (*s)
			wc++;
		while (*s && !ft_isspace(*s))
			s++;
	}
	return (wc);
}

int	loadstack(int ac, char **av, t_ps *ps)
{
	ps->a = parse_args(ac, av);
	ps->size = lstsize(ps->a);
	if (ps->size <= 0)
		return (0);
	return (1);
}

int	load(int ac, char **av, t_ps *ps)
{
	int		nac;

	nac = ft_wc(av[1]);
	if (ac == 2 && nac >= 1)
		return (parse_str(nac, av, ps));
	if (ac > 2 && nac <= 1)
	{
		if (args_are_digits(1, ac, av) && args_are_ints(1, ac, av))
			return (loadstack(1, av, ps));
		return (0);
	}
	return (0);
}
