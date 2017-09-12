/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewen <yewen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 20:51:23 by yewen             #+#    #+#             */
/*   Updated: 2016/03/03 18:39:45 by yewen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ret;

	if (start > ft_strlen(s) - 1)
		return (NULL);
	if ((ret = malloc(len + 1)) == NULL)
		return (NULL);
	ft_strncpy(ret, s + start, len);
	*(ret + len) = '\0';
	return (ret);
}
