/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushback.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewen <yewen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 14:04:56 by yewen             #+#    #+#             */
/*   Updated: 2017/08/17 14:05:58 by yewen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_pushback(void **data, size_t size, int count, void *o)
{
	unsigned char	*p;
	unsigned char	*u;

	p = try(size * (count + 1));
	u = (unsigned char *)*data;
	ft_memcpy(p, u, count * size);
	ft_memcpy(p + count * size, o, size);
	free(*data);
	*data = p;
}
