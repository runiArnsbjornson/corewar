/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewen <yewen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 20:46:07 by yewen             #+#    #+#             */
/*   Updated: 2016/03/21 00:53:04 by yewen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	char	*ptr;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if ((str = malloc(len1 + len2 + 1)) == NULL)
		return (NULL);
	ptr = str;
	while (*s1 != '\0')
		*ptr++ = *s1++;
	while ((*ptr++ = *s2++) != '\0')
		;
	return (str);
}
