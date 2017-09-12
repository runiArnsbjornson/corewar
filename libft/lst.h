/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewen <yewen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 08:51:46 by yewen             #+#    #+#             */
/*   Updated: 2017/07/15 13:24:11 by yewen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LST_H
# define LST_H
# include <stddef.h>

typedef struct	s_lst_node
{
	void				*data;
	struct s_lst_node	*prev;
	struct s_lst_node	*next;
}				t_lst_node;

typedef struct	s_lst
{
	t_lst_node	*head;
	int			count;
	int			(*cmp)();
	void		(*delfn)();
}				t_lst;

t_lst			*lst_init(int (*cmp)(), void (*delfn)());
t_lst_node		*lst_new_node(void *data);
void			lst_iter(t_lst *lst, void (*fn)());
void			lst_insert(t_lst *lst, t_lst_node *node);
void			lst_delete(t_lst *lst, t_lst_node *node);
void			lst_remove(t_lst *lst, void *data);
void			lst_push(t_lst *lst, void *data);
void			lst_push_back(t_lst *lst, void *data);
void			*lst_pop(t_lst *lst);
t_lst_node		*lst_search(t_lst *lst, void *data);
void			lst_reverse(t_lst *lst);
void			lst_sort(t_lst *lst);
int				lst_issorted(t_lst *lst);
void			lst_rotate(t_lst *lst);
void			lst_reverse_rotate(t_lst *lst);
void			lst_swap(t_lst *lst);
void			lst_destroy(t_lst *lst);

#endif
