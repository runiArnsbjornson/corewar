/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ultoa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewen <yewen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 23:03:13 by yewen             #+#    #+#             */
/*   Updated: 2017/02/07 09:46:45 by yewen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "printflocal.h"

static char	*ultoa_dec(U_LONG val, char *cp)
{
	long	sval;

	if (val < 10)
	{
		*--cp = FT_TOCHAR(val);
		return (cp);
	}
	if (val > LONG_MAX)
	{
		*--cp = FT_TOCHAR(val % 10);
		sval = val / 10;
	}
	else
		sval = val;
	*--cp = FT_TOCHAR(sval % 10);
	sval /= 10;
	while (sval != 0)
	{
		*--cp = FT_TOCHAR(sval % 10);
		sval /= 10;
	}
	return (cp);
}

static char	*ultoa_oct(U_LONG val, char *cp, int octzero)
{
	*--cp = FT_TOCHAR(val & 7);
	val >>= 3;
	while (val)
	{
		*--cp = FT_TOCHAR(val & 7);
		val >>= 3;
	}
	if (octzero && *cp != '0')
		*--cp = '0';
	return (cp);
}

static char	*ultoa_hex(U_LONG val, char *cp, const char *xdigs)
{
	*--cp = xdigs[val & 15];
	val >>= 4;
	while (val)
	{
		*--cp = xdigs[val & 15];
		val >>= 4;
	}
	return (cp);
}

char		*ultoa(t_pf *pf, U_LONG val, char *endp)
{
	char	*cp;

	cp = endp;
	if (pf->base == 10)
		cp = ultoa_dec(val, cp);
	else if (pf->base == 8)
		cp = ultoa_oct(val, cp, pf->flags & ALT);
	else if (pf->base == 16)
		cp = ultoa_hex(val, cp, pf->xdigs);
	return (cp);
}
