/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewen <yewen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 16:04:18 by yewen             #+#    #+#             */
/*   Updated: 2017/08/18 00:05:24 by yewen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_array	ft_array(void *t, size_t size, int n)
{
	return ((t_array){t, size, n});
}

void	*ft_array_find(t_array t, void *ref, int (*f)())
{
	int		i;
	void	*p;

	i = 0;
	p = t.t;
	while (i < t.n)
	{
		if (f(ref, p))
			return (p);
		p += t.size;
		++i;
	}
	return (NULL);
}
