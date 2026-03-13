/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 15:00:00 by rmwegat           #+#    #+#             */
/*   Updated: 2026/03/13 12:56:27 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*new_node(int value)
{
	t_stack	*node;

	node = ft_malloc(sizeof(t_stack));
	if (!node)
		ft_error();
	node->value = value;
	node->index = 0;
	node->next = NULL;
	return (node);
}

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

static void	check_duplicates(t_stack *a)
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
				ft_error();
			j = j->next;
		}
		i = i->next;
	}
}

void	init_stack(t_stack **a, int argc, char **argv)
{
	int		i;
	long	nb;
	char	**args;
	int		j;

	i = 1;
	while (i < argc)
	{
		args = ft_split(argv[i], ' ');
		j = 0;
		while (args[j])
		{
			nb = ft_atoi(args[j]);
			if (nb > 2147483647 || nb < -2147483648)
				ft_error();
			add_node_back(a, new_node((int)nb));
			j++;
		}
		i++;
	}
	check_duplicates(*a);
	assign_index(*a, get_stack_size(*a));
}