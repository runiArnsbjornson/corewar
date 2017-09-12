/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_search.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewen <yewen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 23:45:51 by yewen             #+#    #+#             */
/*   Updated: 2016/12/06 23:50:49 by yewen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rb.h"

void	*rb_search(t_rb *rb, void *key)
{
	t_rb_node	*x;
	int			cmp;

	x = rb->root;
	while (x != NULL)
	{
		cmp = rb->cmpfn(key, x->key);
		if (cmp == 0)
			return (x->data);
		else if (cmp < 0)
			x = x->left;
		else if (cmp > 0)
			x = x->right;
	}
	return (NULL);
}
