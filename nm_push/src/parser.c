/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:24:16 by nmihaile          #+#    #+#             */
/*   Updated: 2023/12/19 14:07:15 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

static void	ft_spacify(char *str)
{
	while (*str)
	{
		if (ft_isspace(*str))
			*str = ' ';
		str++;
	}
}

static void	free_nargs(char **nbrs)
{
	int	i;

	i = 0;
	while (nbrs[i])
	{
		free(nbrs[i]);
		i++;
	}
	free(nbrs);
}

int	parse_str(int ac, char **av, t_ps *ps)
{
	char	**argn;
	int		error;

	if (av[1][0] == 0)
		return (0);
	ft_spacify(av[1]);
	argn = ft_split(av[1], ' ');
	if (argn == NULL)
		return (0);
	if (args_are_digits(0, ac, argn) && args_are_ints(0, ac, argn))
		error = loadstack(0, argn, ps);
	else
		error = 0;
	free_nargs(argn);
	return (error);
}

t_lst	*parse_args(int ac_offset, char **av)
{
	int		i;
	t_lst	*lst;

	lst = NULL;
	i = ac_offset;
	while (av[i])
	{
		lstadd_back(&lst, lstnew(ft_atoi(av[i])));
		i++;
	}
	return (lst);
}
