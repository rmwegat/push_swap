/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:20:47 by rwegat            #+#    #+#             */
/*   Updated: 2024/01/16 20:02:48 by rwegat           ###   ########.fr       */
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
	bool				cheapest;
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
void			ft_lstadd_back(t_stack_node **lst, t_stack_node *new);
int				ft_lstsize(t_stack_node *lst);
t_stack_node	*ft_lstnew(void *value);

//		stack utils

t_stack_node	*find_highest(t_stack_node *stack);
t_stack_node	*find_lowest(t_stack_node *stack);
bool			is_sorted(t_stack_node *stack);
int				get_stack_len(t_stack_node *stack);

//		sorting algorihthms

void			push_swap(t_stack_node **a, t_stack_node **b);
void			sort_3(t_stack_node **a);
void			sort_5(t_stack_node **a, t_stack_node **b);

//		error handling

#endif