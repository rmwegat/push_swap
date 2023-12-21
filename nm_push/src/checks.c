/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 10:43:22 by nmihaile          #+#    #+#             */
/*   Updated: 2023/12/19 14:07:18 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

int	is_unique(t_lst *lst)
{
	t_lst	*it;

	if (lst == NULL)
		return (1);
	it = lst->next;
	while (lst)
	{
		if (it && it->value == lst->value && it != lst)
			return (0);
		if (it && it->next)
			it = it->next;
		else
		{
			lst = lst->next;
			if (lst)
				it = lst->next;
			else
				it = NULL;
		}
	}
	return (1);
}

int	args_are_digits(int threshold, int ac, char **av)
{
	int	i;

	ac -= 1;
	while (ac >= threshold)
	{
		i = 0;
		while (av[ac][i])
		{
			if (i == 0 && av[ac][i] == '-')
				i++;
			if (!ft_isdigit(av[ac][i]))
				return (0);
			i++;
		}
		ac--;
	}
	return (1);
}

int	is_sorted(t_lst *lst)
{
	int	v;

	if (lst == NULL)
		return (0);
	v = lst->value;
	while (lst)
	{
		if (lst->next && v > lst->next->value)
			return (0);
		lst = lst->next;
		if (lst)
			v = lst->value;
	}
	return (1);
}

static int	is_intstr(char *s)
{
	unsigned int	n;
	int				sign;

	n = 0;
	sign = 1;
	while (ft_isspace(*s))
		s++;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (*s && ft_isdigit(*s))
	{
		n = n * 10 + (*s - 48);
		s++;
	}
	if (sign > 0 && n <= 2147483647)
		return (1);
	else if (sign < 0 && n <= 2147483648)
		return (1);
	return (0);
}

int	args_are_ints(int offset, int ac, char **av)
{
	int	i;

	i = offset;
	while (i < ac)
	{
		if (is_intstr(&av[i][0]) == 0)
			return (0);
		i++;
	}
	return (1);
}
