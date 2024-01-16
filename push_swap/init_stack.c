/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 23:06:06 by rwegat            #+#    #+#             */
/*   Updated: 2024/01/16 19:38:00 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static long	atol(const char *str)
{
	long	nbr;
	int		polarization;
	int		i;

	nbr = 0;
	polarization = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		polarization = -1;
		i++;
	}
	while (str[i] >= 0 && str[i] <= 9)
	{
		nbr = (nbr * 10) + (str[i] - '0');
		i++;
	}
	return (nbr * polarization);
}

bool	init_stack(t_stack_node **a, int *argv[])
{
	long			nbr;
	int				i;
	t_stack_node	*new_node;

	i = 0;
	while (argv[i])
	{
		nbr = atol(argv[i]);
		new_node = ft_lstnew(nbr);
		ft_lstadd_back(a, new_node);
		i++;
	}
}
//no error handling