/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewen <yewen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 20:31:58 by yewen             #+#    #+#             */
/*   Updated: 2016/04/06 19:08:34 by yewen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	ft_itoa_size(int n)
{
	size_t	size;

	size = 1;
	while (n / 10 != 0)
	{
		n /= 10;
		++size;
	}
	return (n < 0 ? ++size : size);
}

char			*ft_itoa(int n)
{
	char		*ret;
	size_t		size;
	const char	*charset;

	size = ft_itoa_size(n);
	if ((ret = malloc(size + 1)) == NULL)
		return (NULL);
	charset = "0123456789";
	ret += size;
	*ret = '\0';
	while (n / 10 != 0)
	{
		*--ret = charset[FT_ABS(n % 10)];
		n /= 10;
	}
	*--ret = charset[FT_ABS(n)];
	if (n < 0)
		*--ret = '-';
	return (ret);
}
