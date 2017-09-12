/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewen <yewen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 20:51:15 by yewen             #+#    #+#             */
/*   Updated: 2016/02/28 13:18:01 by yewen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s, const char *find)
{
	size_t	len;

	if (*find == '\0')
		return ((char *)s);
	len = ft_strlen(find);
	while (*s != '\0')
	{
		if (ft_strncmp(s, find, len) == 0)
			return ((char *)s);
		++s;
	}
	return (NULL);
}
