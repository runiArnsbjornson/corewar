/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewen <yewen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 19:34:33 by yewen             #+#    #+#             */
/*   Updated: 2016/04/09 14:43:56 by yewen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_swap(void *a, void *b, size_t width)
{
	char	tmp[width];

	ft_memcpy(tmp, b, width);
	ft_memcpy(b, a, width);
	ft_memcpy(a, tmp, width);
}

void		ft_qsort(void *base, size_t n, size_t width,
			int (*cmp)(const void *, const void *))
{
	int		i;
	int		j;
	char	p[width];

	if (n < 2)
		return ;
	ft_memcpy(p, base + n / 2 * width, width);
	i = 0;
	j = n - 1;
	while (1)
	{
		while (cmp(base + i * width, p) < 0)
			++i;
		while (cmp(p, base + j * width) < 0)
			--j;
		if (i >= j)
			break ;
		ft_swap((base + i++ * width), (base + j-- * width), width);
	}
	ft_qsort(base, i, width, cmp);
	ft_qsort(base + i * width, n - i, width, cmp);
}
