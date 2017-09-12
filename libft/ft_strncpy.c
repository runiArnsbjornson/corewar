/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewen <yewen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 20:48:16 by yewen             #+#    #+#             */
/*   Updated: 2016/02/21 12:10:43 by yewen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*save;

	save = dst;
	while (len-- != 0)
	{
		if ((*dst++ = *src++) == '\0')
		{
			while (len-- != 0)
				*dst++ = '\0';
			break ;
		}
	}
	return (save);
}
