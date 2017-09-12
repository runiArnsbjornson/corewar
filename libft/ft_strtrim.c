/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewen <yewen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 20:51:32 by yewen             #+#    #+#             */
/*   Updated: 2017/02/01 13:38:56 by yewen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char		*ret;
	size_t		len;
	const char	*ptr;

	ptr = s + ft_strlen(s) - 1;
	while (FT_ISSPACE(*ptr) && ptr >= s)
		--ptr;
	while (FT_ISSPACE(*s))
		++s;
	len = ptr > s ? ptr - s + 1 : 0;
	if ((ret = malloc(len + 1)) == NULL)
		return (NULL);
	ft_strncpy(ret, s, len);
	*(ret + len) = '\0';
	return (ret);
}
