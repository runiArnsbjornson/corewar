/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_type_helper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewen <yewen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 18:14:22 by yewen             #+#    #+#             */
/*   Updated: 2017/03/05 22:47:02 by yewen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printflocal.h"

void	pf_get_cc(t_pf *pf)
{
	if (pf->ch == 'C')
		pf->flags |= LONGINT;
	if (pf->flags & LONGINT)
	{
		pf->cp = pf->buf;
		wctostr(va_arg(pf->ap, wchar_t), pf->cp, &pf->size);
	}
	else
	{
		pf->cp = pf->buf;
		*pf->cp = va_arg(pf->ap, int);
		pf->size = 1;
	}
	pf->sign = '\0';
}

void	pf_get_ss(t_pf *pf)
{
	wchar_t	*wcp;

	if (pf->ch == 'S')
		pf->flags |= LONGINT;
	if (pf->flags & LONGINT)
	{
		if (pf->convbuf != NULL)
			ft_strdel(&pf->convbuf);
		if ((wcp = va_arg(pf->ap, wchar_t *)) == NULL)
			pf->cp = "(null)";
		else
		{
			pf->convbuf = wstostr(wcp);
			pf->cp = pf->convbuf;
		}
	}
	else if ((pf->cp = va_arg(pf->ap, char *)) == NULL)
		pf->cp = "(null)";
	pf->size = (pf->prec >= 0) ? ft_strnlen(pf->cp, pf->prec) \
		: ft_strlen(pf->cp);
	pf->sign = '\0';
}

void	pf_get_p(t_pf *pf)
{
	pf->ujval = (uintmax_t)((uintptr_t)va_arg(pf->ap, void *));
	pf->base = 16;
	pf->xdigs = XDIGS_LOWER;
	pf->flags |= INTMAXT;
	pf->ox[1] = 'x';
	pf_nosign(pf);
}

void	pf_set_n(t_pf *pf)
{
	if (pf->flags & LLONGINT)
		*va_arg(pf->ap, long long *) = pf->ret;
	else if (pf->flags & SIZET)
		*va_arg(pf->ap, ssize_t *) = (ssize_t)pf->ret;
	else if (pf->flags & INTMAXT)
		*va_arg(pf->ap, intmax_t *) = pf->ret;
	else if (pf->flags & LONGINT)
		*va_arg(pf->ap, long *) = pf->ret;
	else if (pf->flags & SHORTINT)
		*va_arg(pf->ap, short *) = pf->ret;
	else if (pf->flags & CHARINT)
		*va_arg(pf->ap, signed char *) = pf->ret;
	else
		*va_arg(pf->ap, int *) = pf->ret;
}
