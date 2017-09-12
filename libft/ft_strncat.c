/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewen <yewen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 20:47:43 by yewen             #+#    #+#             */
/*   Updated: 2016/02/29 21:00:03 by yewen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dst, const char *src, size_t n)
{
	char	*save;

	save = dst;
	while (*dst != '\0')
		++dst;
	while (*src != '\0' && n-- != 0)
		*dst++ = *src++;
	*dst = '\0';
	return (save);
}
