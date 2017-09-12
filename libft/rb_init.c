/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewen <yewen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 10:32:51 by yewen             #+#    #+#             */
/*   Updated: 2017/07/14 14:03:41 by yewen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rb.h"

t_rb	*rb_init(int (*cmpfn)(), void (*deldata)(), void (*delkey)())
{
	t_rb	*rb;

	rb = malloc(sizeof(*rb));
	if (rb == NULL)
		return (NULL);
	rb->root = NULL;
	rb->cmpfn = cmpfn;
	rb->deldata = deldata;
	rb->delkey = delkey;
	return (rb);
}
