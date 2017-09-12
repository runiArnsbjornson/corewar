/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewen <yewen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 18:50:09 by yewen             #+#    #+#             */
/*   Updated: 2017/08/14 11:42:37 by yewen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strndup(const char *str, size_t maxlen)
{
	char	*copy;
	size_t	len;

	len = ft_strnlen(str, maxlen);
	if ((copy = malloc(len + 1)) == NULL)
		return (NULL);
	ft_memcpy(copy, str, len);
	*(copy + len) = '\0';
	return (copy);
}
