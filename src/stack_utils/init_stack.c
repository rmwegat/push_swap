/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 16:25:18 by rwegat            #+#    #+#             */
/*   Updated: 2026/05/13 13:12:41 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	add_node_back(t_stack **stack, t_stack *node)
{
	t_stack	*tmp;

	if (!*stack)
	{
		*stack = node;
		return ;
	}
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
}

static void	check_duplicates(t_stack *a, t_list **alloc_list)
{
	t_stack	*i;
	t_stack	*j;

	i = a;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->value == j->value)
				ft_error(alloc_list);
			j = j->next;
		}
		i = i->next;
	}
}

static t_stack	*new_node(int value, t_list **alloc_list)
{
	t_stack	*node;

	node = ft_malloc(sizeof(t_stack), alloc_list);
	if (!node)
		ft_error(alloc_list);
	node->value = value;
	node->index = 0;
	node->next = NULL;
	return (node);
}

static long	ft_atol(const char *str, t_list **alloc_list)
{
	long	res;
	int		sign;
	int		i;

	res = 0;
	sign = 1;
	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (!str[i])
		ft_error(alloc_list);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			ft_error(alloc_list);
		res = res * 10 + (str[i] - '0');
		if ((sign * res) > 2147483647 || (sign * res) < -2147483648)
			ft_error(alloc_list);
		i++;
	}
	return (res * sign);
}

void	init_stack(t_stack **a, int argc, char **argv, t_list **alloc_list)
{
	int		i;
	long	nb;
	char	**args;
	int		j;

	i = 1;
	while (i < argc)
	{
		args = ft_split(argv[i], ' ');
		if (!args || !args[0])
			ft_error(alloc_list);
		j = 0;
		while (args[j])
		{
			nb = ft_atol(args[j], alloc_list);
			add_node_back(a, new_node((int)nb, alloc_list));
			j++;
		}
		free_stuff(args);
		i++;
	}
	check_duplicates(*a, alloc_list);
	assign_index(*a, get_stack_size(*a));
}
