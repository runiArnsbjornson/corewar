/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ujtoa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewen <yewen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 00:53:57 by yewen             #+#    #+#             */
/*   Updated: 2017/02/07 09:46:31 by yewen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "printflocal.h"

static char	*ujtoa_dec(uintmax_t val, char *cp)
{
	int	sval;

	if (val < 10)
	{
		*--cp = FT_TOCHAR(val % 10);
		return (cp);
	}
	if (val > INTMAX_MAX)
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

static char	*ujtoa_oct(uintmax_t val, char *cp, int octzero)
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

static char	*ujtoa_hex(uintmax_t val, char *cp, const char *xdigs)
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

char		*ujtoa(t_pf *pf, uintmax_t val, char *endp)
{
	char	*cp;

	if (val <= ULONG_MAX)
		return (ultoa(pf, (U_LONG)val, endp));
	cp = endp;
	if (pf->base == 10)
		cp = ujtoa_dec(val, cp);
	else if (pf->base == 8)
		cp = ujtoa_oct(val, cp, pf->flags & ALT);
	else if (pf->base == 16)
		cp = ujtoa_hex(val, cp, pf->xdigs);
	return (cp);
}
