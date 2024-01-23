/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:53:35 by rwegat            #+#    #+#             */
/*   Updated: 2024/01/22 16:58:11 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# define BUFFER_SIZE 4
# include <fcntl.h>
# include "../push_swap/pushswap.h"

typedef struct s_list
{
	char			*str_buf;
	struct s_list	*next;
}				t_list;

//		get_next_line

char	*get_next_line(int fd);
t_list	*find_last(t_list *lst);
void	lst_add_back(t_list **list, char *buf);
int		find_newline(t_list *list);
void	copy_str(t_list *list, char *next_str);
void	free_list(t_list **list, t_list *clean_node, char *buf);

#endif