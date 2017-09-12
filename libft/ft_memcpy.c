/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewen <yewen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 20:41:36 by yewen             #+#    #+#             */
/*   Updated: 2016/03/03 18:37:06 by yewen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*dstp;
	const unsigned char	*srcp;

	dstp = dst;
	srcp = src;
	while (n-- != 0)
		*dstp++ = *srcp++;
	return (dst);
}
