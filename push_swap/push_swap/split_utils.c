/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:03:06 by rwegat            #+#    #+#             */
/*   Updated: 2024/01/24 16:06:28 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(char *)(s + i) = 0;
		i++;
	}
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;

	i = 0;
	s2 = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) + 1));
	if (!s2)
		return (NULL);
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	i;
	size_t			y;

	y = 0;
	i = 0;
	if (ft_strlen(s) <= start)
		return (ft_strdup(""));
	if ((ft_strlen(s) - start) < len)
		len = ft_strlen(s) - start;
	substr = (char *)malloc(sizeof(char) * len + 1);
	if (!substr)
		return (NULL);
	while (s[i])
	{
		if ((y < len) && (i >= start))
		{
			substr[y] = s[i];
			y++;
		}
		i++;
	}
	substr[y] = '\0';
	return (substr);
}
