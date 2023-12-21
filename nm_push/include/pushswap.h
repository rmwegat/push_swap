/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:13:15 by nmihaile          #+#    #+#             */
/*   Updated: 2023/12/20 11:19:23 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <unistd.h>
# include "../libft/libft.h"

# define TRUE 1
# define FALSE 0

typedef struct s_lst	t_lst;

typedef struct s_ps
{
	t_lst	*a;
	t_lst	*b;
	t_lst	*s;
	size_t	size;
}	t_ps;

typedef struct s_lst
{
	struct s_lst	*prev;
	struct s_lst	*next;
	struct s_lst	*target;
	int				value;
	unsigned int	id;
	unsigned int	cost;
	int				dir;
	int				td;
}	t_lst;

//			List Functions
t_lst			*lstnew(int nb);
void			lstadd_front(t_lst **pl, t_lst *lst);
void			lstadd_back(t_lst **pl, t_lst *new);
void			lstswp(t_lst **head, t_lst *a, t_lst *b);
//
size_t			lstsize(t_lst *lst);
int				issizeof3(t_lst *lst);
t_lst			*lstlast(t_lst *lst);
void			clrlst(t_lst **lst);
//
int				lst_isadj(t_lst *a, t_lst *b);
void			lst_updadj(t_lst *lst);
void			lstset_pevnext(t_lst *lst, t_lst *p, t_lst *n);
void			swaplstptrs(t_lst **a, t_lst **b);

//			Flag Functions
void			leaks(void);
void			checkleaks(void);

//			ps_utls Functions
int				ft_isspace(char c);
char			*ft_skipspace(char *s);

//			Parser Functions
int				parse_str(int ac, char **av, t_ps *ps);
t_lst			*parse_args(int ac_offset, char **av);

//			loader Functions
int				ft_wc(char *s);
int				loadstack(int ac, char **av, t_ps *ps);
int				load(int ac, char **av, t_ps *ps);

//			check Functions
int				is_unique(t_lst *lst);
int				args_are_digits(int offset, int ac, char **av);
int				is_sorted(t_lst *lst);
int				args_are_ints(int offset, int ac, char **av);

//			stack operation Functions
void			sa(t_ps *ps, char print);
void			sb(t_ps *ps, char print);
void			ss(t_ps *ps, char print);
void			pa(t_ps *ps, char print);
void			pb(t_ps *ps, char print);
void			ra(t_ps *ps, char print);
void			rb(t_ps *ps, char print);
void			rr(t_ps *ps, char print);
void			rra(t_ps *ps, char print);
void			rrb(t_ps *ps, char print);
void			rrr(t_ps *ps, char print);

//			id
void			populate_ids_of_stack(t_lst *stack);
void			create_ids(t_ps *ps);

//			target
void			settargets(t_ps *ps);

//			cost
void			topcost(t_lst *lst);
void			idcost(t_ps *ps);
t_lst			*get_cheapest(t_lst *stack);
t_lst			*get_smalestid(t_lst *stack);

//			move
unsigned int	steps_to_move_up(int *dir, t_lst *it, t_lst *st);
void			move(t_lst *it, t_ps *ps);

//			sort
void			sort_by_value(t_lst **lst);
void			pre_sort_to_stack_b(t_ps *ps);
void			sort(t_ps *ps);

#endif