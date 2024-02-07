/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:20:47 by rwegat            #+#    #+#             */
/*   Updated: 2024/02/07 18:47:50 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_stack_node
{
	int					value;
	int					current_position;
	int					push_price;
	bool				is_cheapest;
	bool				above_middle;
	struct s_stack_node	*next;
	struct s_stack_node	*previous;
	struct s_stack_node	*target_node;
}	t_stack_node;

//		swapping functions

void			sa(t_stack_node **a);
void			sb(t_stack_node **b);
void			ss(t_stack_node **a, t_stack_node **b);
void			p_to_a(t_stack_node **a, t_stack_node **b);
void			p_to_b(t_stack_node **a, t_stack_node **b);
void			ra(t_stack_node **a);
void			rb(t_stack_node **b);
void			rr(t_stack_node **a, t_stack_node **b);
void			rra(t_stack_node **a);
void			rrb(t_stack_node **b);
void			rrr(t_stack_node **a, t_stack_node **b);

//		input handling and split

size_t			ft_strlen(const char *str);
void			ft_bzero(void *s, size_t n);
char			*ft_strdup(const char *s1);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			**ft_split(char const *s, char c);

//		stack functions from libft

t_stack_node	*ft_lstlast(t_stack_node *lst);
void			ft_lstadd_front(t_stack_node **lst, t_stack_node *new);
void			ft_lstadd_back(t_stack_node **lst, int nbr);
t_stack_node	*ft_lstnew(void *value);

//		stack utils

t_stack_node	*get_highest(t_stack_node *stack);
t_stack_node	*get_lowest(t_stack_node *stack);
t_stack_node	*get_cheapest(t_stack_node *stack);
bool			is_sorted(t_stack_node *stack);
int				get_stack_len(t_stack_node *stack);
bool			init_stack(t_stack_node **a, char *argv[]);
void			set_current_position(t_stack_node *stack);

//		for sorting

void			push_swap(t_stack_node **a, t_stack_node **b);
void			sort_3(t_stack_node **a);
void			init_nodes(t_stack_node *a, t_stack_node *b);
void			do_cheapest_push(t_stack_node **a, t_stack_node **b);

//		error handling

void			free_stack(t_stack_node **stack);

#endif