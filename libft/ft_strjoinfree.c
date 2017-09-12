/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewen <yewen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 16:39:59 by yewen             #+#    #+#             */
/*   Updated: 2017/08/18 23:41:10 by yewen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#define FREE_S1		1
#define FREE_S2		2

char	*ft_strjoinfree(char const *s1, char const *s2, int mask)
{
	char	*o;
	int		i;
	int		j;

	i = -1;
	j = -1;
	if ((o = malloc(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1)) == NULL)
		return (NULL);
	if (s1)
		while (s1[++i])
			o[i] = s1[i];
	i = i == -1 ? 0 : i;
	if (s2 != NULL)
		while (s2[++j])
			o[i + j] = s2[j];
	j = j == -1 ? 0 : j;
	o[i + j] = '\0';
	if (mask & FREE_S1)
		ft_memdel((void **)&s1);
	if (mask & FREE_S2)
		ft_memdel((void **)&s2);
	return (o);
}
