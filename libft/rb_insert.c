/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_insert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewen <yewen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 22:51:05 by yewen             #+#    #+#             */
/*   Updated: 2017/07/14 14:05:27 by yewen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rb.h"

static t_rb_node	*rb_new_node(void *key, void *data)
{
	t_rb_node	*h;

	h = malloc(sizeof(*h));
	if (h == NULL)
		return (NULL);
	h->key = key;
	h->data = data;
	h->left = NULL;
	h->right = NULL;
	h->color = RED;
	return (h);
}

static t_rb_node	*insert(t_rb *rb, t_rb_node *h, void *key, void *data)
{
	int	cmp;

	if (h == NULL)
		return (rb_new_node(key, data));
	cmp = rb->cmpfn(key, h->key);
	if (cmp == 0)
		h->data = data;
	else if (cmp < 0)
		h->left = insert(rb, h->left, key, data);
	else
		h->right = insert(rb, h->right, key, data);
	if (rb_is_red(h->right) && !rb_is_red(h->left))
		h = rb_rotate_left(h);
	if (rb_is_red(h->left) && rb_is_red(h->left->left))
		h = rb_rotate_right(h);
	if (rb_is_red(h->left) && rb_is_red(h->right))
		rb_flip_color(h);
	return (h);
}

void				rb_insert(t_rb *rb, void *key, void *data)
{
	rb->root = insert(rb, rb->root, key, data);
	rb->root->color = BLACK;
}
