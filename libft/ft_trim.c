/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewen <yewen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 14:11:13 by yewen             #+#    #+#             */
/*   Updated: 2017/08/17 14:11:13 by yewen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_trim(char **s)
{
	char	*p;

	p = ft_strtrim(*s);
	if (*s)
		ft_memdel((void **)s);
	*s = p;
	return (*s);
}