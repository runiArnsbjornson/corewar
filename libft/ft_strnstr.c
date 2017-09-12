/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewen <yewen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 20:48:50 by yewen             #+#    #+#             */
/*   Updated: 2016/02/29 15:23:54 by yewen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s, const char *find, size_t len)
{
	char	*pos;

	pos = ft_strstr(s, find);
	if (pos - s + ft_strlen(find) > len)
		return (NULL);
	return (pos);
}
