/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 16:25:09 by rwegat            #+#    #+#             */
/*   Updated: 2026/03/27 14:10:32 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(t_list **alloc_list)
{
	ft_putstr_fd("Error\n", 2);
	ft_free_all(alloc_list);
	exit(1);
}

// ARG=$(shuf -i 1-100 -n 100 | tr '\n' ' '); echo "$ARG" > input; ./push_swap $ARG >> output
/*
python3 - <<'PY' | tee input.txt | xargs ./push_swap > output.txt
import random
print(' '.join(map(str, random.sample(range(1,501), 500))))
PY
*/
int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_list	*alloc_list;

	a = NULL;
	b = NULL;
	alloc_list = NULL;
	if (argc > 1)
	{
		init_stack(&a, argc, argv, &alloc_list);
		if (!is_sorted(a))
			sort_stack(&a, &b);
	}
	ft_free_all(&alloc_list);
	return (0);
}
