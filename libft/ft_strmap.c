/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewen <yewen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 20:47:21 by yewen             #+#    #+#             */
/*   Updated: 2016/03/03 19:18:17 by yewen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	char	*ptr;

	if ((str = malloc(ft_strlen(s) + 1)) == NULL)
		return (NULL);
	ptr = str;
	while (*s != '\0')
		*ptr++ = (*f)(*s++);
	*ptr = '\0';
	return (str);
}
