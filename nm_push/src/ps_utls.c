/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utls.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 20:46:59 by nmihaile          #+#    #+#             */
/*   Updated: 2023/12/19 14:07:41 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

int	ft_isspace(char c)
{
	char	*space;

	space = "\t\n\v\f\r ";
	while (*space)
		if (c == *space++)
			return (1);
	return (0);
}

char	*ft_skipspace(char *s)
{
	while (*s && ft_isspace(*s))
		s++;
	return (s);
}
