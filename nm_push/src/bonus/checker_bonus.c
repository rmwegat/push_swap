/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:15:06 by nmihaile          #+#    #+#             */
/*   Updated: 2023/12/20 15:46:57 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pushswap.h"

static void	free_stacks(t_ps *ps)
{
	if (ps->a)
		clrlst(&ps->a);
	if (ps->b)
		clrlst(&ps->b);
	if (ps->s)
		clrlst(&ps->s);
}

static int	execute_instructions(char *line, t_ps *ps)
{
	if (ft_strncmp(line, "pa\n", ft_strlen(line)) == 0)
		pa(ps, 0);
	else if (ft_strncmp(line, "pb\n", ft_strlen(line)) == 0)
		pb(ps, 0);
	else if (ft_strncmp(line, "rra\n", ft_strlen(line)) == 0)
		rra(ps, 0);
	else if (ft_strncmp(line, "rrb\n", ft_strlen(line)) == 0)
		rrb(ps, 0);
	else if (ft_strncmp(line, "rrr\n", ft_strlen(line)) == 0)
		rrr(ps, 0);
	else if (ft_strncmp(line, "ra\n", ft_strlen(line)) == 0)
		ra(ps, 0);
	else if (ft_strncmp(line, "rb\n", ft_strlen(line)) == 0)
		rb(ps, 0);
	else if (ft_strncmp(line, "rr\n", ft_strlen(line)) == 0)
		rr(ps, 0);
	else if (ft_strncmp(line, "sa\n", ft_strlen(line)) == 0)
		sa(ps, 0);
	else if (ft_strncmp(line, "sb\n", ft_strlen(line)) == 0)
		sb(ps, 0);
	else if (ft_strncmp(line, "ss\n", ft_strlen(line)) == 0)
		ss(ps, 0);
	else
		return (1);
	return (0);
}

static int	read_instructions(t_ps *ps)
{
	char	*line;

	while (1)
	{
		line = get_next_line(STDIN_FILENO);
		if (line == NULL)
			break ;
		if (execute_instructions(line, ps) == TRUE)
		{
			free(line);
			line = NULL;
			return (1);
		}
		else
		{
			free(line);
			line = NULL;
		}
	}
	if (line)
		free(line);
	return (0);
}

static void	run(t_ps *ps)
{
	int			error;

	error = 0;
	error = read_instructions(ps);
	if (error)
		write(2, "Error\n", 6);
	else
	{
		if (is_sorted(ps->a) == TRUE)
			ft_printf("\033[0;92mOK\033[0m\n");
		else
			ft_printf("\033[0;91mKO\033[0m\n");
	}
}

int	main(int ac, char **av)
{
	static t_ps	ps;

	if (ac > 1)
	{
		if (av[1][0])
		{
			if (load(ac, av, &ps) && is_unique(ps.a))
			{
				create_ids(&ps);
				run(&ps);
			}
			else
				write(2, "Error\n", 6);
		}
	}
	free_stacks(&ps);
	return (0);
}
