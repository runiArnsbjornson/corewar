/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewen <yewen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 20:52:06 by yewen             #+#    #+#             */
/*   Updated: 2017/02/07 09:43:08 by yewen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printflocal.h"

long		sarg(t_pf *pf, int flags)
{
	if (flags & LONGINT)
		return (va_arg(pf->ap, long));
	if (flags & SHORTINT)
		return ((long)(short)va_arg(pf->ap, int));
	if (flags & CHARINT)
		return ((long)(signed char)va_arg(pf->ap, int));
	return ((long)va_arg(pf->ap, int));
}

U_LONG		uarg(t_pf *pf, int flags)
{
	if (flags & LONGINT)
		return (va_arg(pf->ap, U_LONG));
	if (flags & SHORTINT)
		return ((U_LONG)(unsigned short)va_arg(pf->ap, int));
	if (flags & CHARINT)
		return ((U_LONG)(unsigned char)va_arg(pf->ap, int));
	return ((U_LONG)va_arg(pf->ap, unsigned int));
}

intmax_t	sjarg(t_pf *pf, int flags)
{
	if (flags & INTMAXT)
		return (va_arg(pf->ap, intmax_t));
	if (flags & SIZET)
		return ((intmax_t)va_arg(pf->ap, ssize_t));
	return ((intmax_t)va_arg(pf->ap, long long));
}

uintmax_t	ujarg(t_pf *pf, int flags)
{
	if (flags & INTMAXT)
		return (va_arg(pf->ap, uintmax_t));
	if (flags & SIZET)
		return ((uintmax_t)va_arg(pf->ap, size_t));
	return ((uintmax_t)va_arg(pf->ap, unsigned long long));
}

void		getaster(t_pf *pf, int *val)
{
	pf->n2 = 0;
	pf->cp = pf->fmt;
	while (FT_ISDIGIT(*pf->cp))
	{
		pf->n2 = 10 * pf->n2 + FT_TODIGIT(*pf->cp);
		++pf->cp;
	}
	*val = va_arg(pf->ap, int);
}
