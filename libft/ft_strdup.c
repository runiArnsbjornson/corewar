/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewen <yewen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 20:43:27 by yewen             #+#    #+#             */
/*   Updated: 2017/02/18 14:42:22 by yewen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	len;
	char	*copy;

	len = ft_strlen(str) + 1;
	if ((copy = malloc(len)) == NULL)
		return (NULL);
	ft_memcpy(copy, str, len);
	return (copy);
}
