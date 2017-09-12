/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_delete.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewen <yewen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 23:53:49 by yewen             #+#    #+#             */
/*   Updated: 2017/07/14 14:08:22 by yewen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rb.h"

static t_rb_node	*move_red_left(t_rb_node *h)
{
	rb_flip_color(h);
	if (h->right && rb_is_red(h->right->left))
	{
		h->right = rb_rotate_right(h->right);
		h = rb_rotate_left(h);
		rb_flip_color(h);
	}
	return (h);
}

static t_rb_node	*move_red_right(t_rb_node *h)
{
	rb_flip_color(h);
	if (h->left && rb_is_red(h->left->left))
	{
		h = rb_rotate_right(h);
		rb_flip_color(h);
	}
	return (h);
}

static t_rb_node	*delete_min(t_rb *rb, t_rb_node *h)
{
	if (h->left == NULL)
		return (rb_free(rb, h));
	if (!rb_is_red(h->left) && !rb_is_red(h->left->left))
		h = move_red_left(h);
	h->left = delete_min(rb, h->left);
	return (rb_fixup(h));
}

static t_rb_node	*delete(t_rb *rb, t_rb_node *h, void *key)
{
	if (rb->cmpfn(key, h->key) < 0)
	{
		if (!rb_is_red(h->left) && !rb_is_red(h->left->left))
			h = move_red_left(h);
		h->left = delete(rb, h->left, key);
	}
	else
	{
		if (rb_is_red(h->left))
			h = rb_rotate_right(h);
		if (rb->cmpfn(key, h->key) == 0 && h->right == NULL)
			return (rb_free(rb, h));
		if (!rb_is_red(h->right) && !rb_is_red(h->right->left))
			h = move_red_right(h);
		if (rb->cmpfn(key, h->key) == 0)
		{
			h->data = rb_min(h)->data;
			h->key = rb_min(h)->key;
			h->right = delete_min(rb, h->right);
		}
		else
			h->right = delete(rb, h->right, key);
	}
	return (rb_fixup(h));
}

void				rb_delete(t_rb *rb, void *key)
{
	rb->root = delete(rb, rb->root, key);
	if (rb->root != NULL)
		rb->root->color = BLACK;
}
