/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewen <yewen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 20:40:15 by yewen             #+#    #+#             */
/*   Updated: 2016/03/03 18:36:20 by yewen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr;
	unsigned char		uc;

	ptr = s;
	uc = c;
	while (n-- != 0)
	{
		if (*ptr == uc)
			return ((void *)ptr);
		++ptr;
	}
	return (NULL);
}
