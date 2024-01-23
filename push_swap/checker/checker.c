/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:08:25 by rwegat            #+#    #+#             */
/*   Updated: 2024/01/23 13:57:37 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	ft_strcmp(char *str_1, char *str_2)
{
	while (*str_1 == *str_2 && *str_1)
	{
		str_1++;
		str_2++;
	}
	return (*str_1 - *str_2);
}

static int do_operations(t_stack_node *a, t_stack_node *b, char *next_line)
{
	if (!ft_strcmp(next_line, "pa\n"))
		pa(a, b);
	else if (!ft_strcmp(next_line, "pb\n"))
		pb(b, a);
	else if (!ft_strcmp(next_line, "sa\n"))
		sa(a);
	else if (!ft_strcmp(next_line, "sb\n"))
		sb(b);
	else if (!ft_strcmp(next_line, "ss\n"))
		ss(a, b);
	else if (!ft_strcmp(next_line, "ra\n"))
		ra(a);
	else if (!ft_strcmp(next_line, "rb\n"))
		rb(b);
	else if (!ft_strcmp(next_line, "rr\n"))
		rr(a, b);
	else if (!ft_strcmp(next_line, "rra\n"))
		rra(a);
	else if (!ft_strcmp(next_line, "rrb\n"))
		rrb(b);
	else if (!ft_strcmp(next_line, "rrr\n"))
		rrr(a, b);
	else
		return(1);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			*next_line;
	int				stack_len;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	stack_len = get_stack_len(a);
	next_line = get_next_line(STDIN_FILENO);
	while (next_line)
	{
		do_operations(&a, &b, next_line);
		next_line = get_next_line(STDIN_FILENO);
	}
	if (is_sorted(&a) && stack_len == get_stack_len(a))
		write (1, "OK\n", 3);
	else
		write (1, "KO\n", 3);
	free(a);
}