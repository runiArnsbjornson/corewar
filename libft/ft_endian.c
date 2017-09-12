/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_endian.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewen <yewen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 15:00:54 by yewen             #+#    #+#             */
/*   Updated: 2017/08/17 18:01:03 by yewen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_endian(void *p, int size)
{
	unsigned char	*o;
	unsigned char	*t;
	int				i;

	if (!(o = ft_memalloc(size)))
		return ;
	t = p;
	i = 0;
	while (i < size)
	{
		o[i] = t[size - i - 1];
		i++;
	}
	ft_memcpy(p, o, size);
	ft_memdel((void **)&o);
}
