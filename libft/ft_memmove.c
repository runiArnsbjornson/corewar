/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewen <yewen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 20:41:56 by yewen             #+#    #+#             */
/*   Updated: 2016/03/03 18:37:31 by yewen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dstp;
	const unsigned char	*srcp;

	if (dst == src || len == 0)
		return (dst);
	dstp = dst;
	srcp = src;
	if (dst < src)
	{
		while (len-- != 0)
			*dstp++ = *srcp++;
	}
	else
	{
		dstp += len - 1;
		srcp += len - 1;
		while (len-- != 0)
			*dstp-- = *srcp--;
	}
	return (dst);
}
