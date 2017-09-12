/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wctostr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewen <yewen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 17:36:35 by yewen             #+#    #+#             */
/*   Updated: 2017/02/07 09:42:54 by yewen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printflocal.h"

static int	nbits(unsigned int nbr)
{
	int	i;

	i = 1;
	while ((nbr = nbr >> 1))
		i++;
	return (i);
}

static int	get_nbytes(unsigned int nbr)
{
	int n;

	n = nbits(nbr);
	if (n < 8)
		return (1);
	else if (n < 12)
		return (2);
	else if (n < 17)
		return (3);
	else
		return (4);
}

void		wctostr(wchar_t wstr, char *cp, int *size)
{
	unsigned int	ch;

	ft_bzero(cp, 5);
	ch = wstr;
	*size = get_nbytes(ch);
	if (*size == 1)
		cp[0] = ch;
	if (*size >= 2)
	{
		cp[0] = ((ch >> 6 * 0) & 63) | 128;
		cp[1] = ((ch >> 6 * 1) & 31) | 192;
	}
	if (*size >= 3)
	{
		cp[1] = ((ch >> 6 * 1) & 63) | 128;
		cp[2] = ((ch >> 6 * 2) & 15) | 224;
	}
	if (*size >= 4)
	{
		cp[2] = ((ch >> 6 * 2) & 63) | 128;
		cp[3] = ((ch >> 6 * 3) & 7) | 240;
	}
	ft_strrev(cp);
}
