/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewen <yewen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 20:40:07 by yewen             #+#    #+#             */
/*   Updated: 2016/03/03 18:36:02 by yewen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*dstp;
	const unsigned char	*srcp;
	unsigned char		uc;

	dstp = dst;
	srcp = src;
	uc = c;
	while (n-- != 0)
		if ((*dstp++ = *srcp++) == uc)
			return (dstp);
	return (NULL);
}
