/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewen <yewen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 09:59:37 by yewen             #+#    #+#             */
/*   Updated: 2017/07/14 14:07:30 by yewen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rb.h"

t_rb_node	*rb_free(t_rb *rb, t_rb_node *h)
{
	if (rb->deldata != NULL)
		rb->deldata(h->data);
	if (rb->delkey != NULL)
		rb->delkey(h->key);
	free(h);
	h = NULL;
	return (h);
}

t_rb_node	*rb_fixup(t_rb_node *h)
{
	if (rb_is_red(h->right))
		h = rb_rotate_left(h);
	if (rb_is_red(h->left) && rb_is_red(h->left->left))
		h = rb_rotate_right(h);
	if (rb_is_red(h->left) && rb_is_red(h->right))
		rb_flip_color(h);
	return (h);
}

t_rb_node	*rb_min(t_rb_node *h)
{
	while (h->left != NULL)
		h = h->left;
	return (h);
}
