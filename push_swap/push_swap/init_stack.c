/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 23:06:06 by rwegat            #+#    #+#             */
/*   Updated: 2024/01/22 15:59:27 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static long	ft_atol(const char *str)
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

bool	init_stack(t_stack_node **a, char *argv[])
{
	long			nbr;
	int				i;

	i = 0;
	while (argv[i])
	{
		nbr = ft_atol(argv[i]);
		ft_lstadd_back(a, (int)nbr);
		i++;
	}
	return (true);
}
//no error handling