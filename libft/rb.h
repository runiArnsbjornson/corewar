/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewen <yewen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 00:52:00 by yewen             #+#    #+#             */
/*   Updated: 2017/07/14 14:00:33 by yewen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RB_H
# define RB_H
# include <stddef.h>

enum			e_rb_color
{
	BLACK,
	RED
};

typedef struct	s_rb_node
{
	struct s_rb_node	*left;
	struct s_rb_node	*right;
	void				*data;
	void				*key;
	enum e_rb_color		color;
}				t_rb_node;

typedef struct	s_rb
{
	t_rb_node	*root;
	int			(*cmpfn)();
	void		(*deldata)();
	void		(*delkey)();
}				t_rb;

t_rb_node		*rb_rotate_left(t_rb_node *h);
t_rb_node		*rb_rotate_right(t_rb_node *h);
void			rb_flip_color(t_rb_node *h);
int				rb_is_red(t_rb_node *h);
t_rb			*rb_init(int (*cmpfn)(), void (*deldata)(), void (*delkey)());
void			rb_insert(t_rb *rb, void *key, void *data);
void			*rb_search(t_rb *rb, void *key);
t_rb_node		*rb_fixup(t_rb_node *h);
t_rb_node		*rb_min(t_rb_node *h);
t_rb_node		*rb_free(t_rb *rb, t_rb_node *h);
void			rb_delete(t_rb *rb, void *key);
void			rb_destroy(t_rb *rb);

#endif
