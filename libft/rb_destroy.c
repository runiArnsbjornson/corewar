/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_destroy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewen <yewen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 18:03:11 by yewen             #+#    #+#             */
/*   Updated: 2016/12/07 18:09:56 by yewen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rb.h"

static t_rb_node	*destroy(t_rb *rb, t_rb_node *h)
{
	if (h == NULL)
		return (NULL);
	if (h->left != NULL)
		destroy(rb, h->left);
	if (h->right != NULL)
		destroy(rb, h->right);
	rb_free(rb, h);
	return (NULL);
}

void				rb_destroy(t_rb *rb)
{
	destroy(rb, rb->root);
	free(rb);
}
