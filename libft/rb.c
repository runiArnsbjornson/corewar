/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewen <yewen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 23:13:18 by yewen             #+#    #+#             */
/*   Updated: 2017/07/14 13:59:59 by yewen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rb.h"

t_rb_node	*rb_rotate_left(t_rb_node *h)
{
	t_rb_node	*x;

	x = h->right;
	h->right = x->left;
	x->left = h;
	x->color = h->color;
	h->color = RED;
	return (x);
}

t_rb_node	*rb_rotate_right(t_rb_node *h)
{
	t_rb_node	*x;

	x = h->left;
	h->left = x->right;
	x->right = h;
	x->color = h->color;
	h->color = RED;
	return (x);
}

void		rb_flip_color(t_rb_node *h)
{
	h->color = !h->color;
	h->left->color = !h->left->color;
	h->right->color = !h->right->color;
}

int			rb_is_red(t_rb_node *h)
{
	return (h ? h->color == RED : 0);
}
