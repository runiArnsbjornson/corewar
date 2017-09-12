/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewen <yewen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 20:49:01 by yewen             #+#    #+#             */
/*   Updated: 2016/03/03 19:18:42 by yewen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*save;
	char	ch;

	save = NULL;
	ch = c;
	while (1)
	{
		if (*s == ch)
			save = (char *)s;
		if (*s == '\0')
			return (save);
		++s;
	}
}
