/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewen <yewen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 20:04:36 by yewen             #+#    #+#             */
/*   Updated: 2017/02/07 09:45:22 by yewen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printflocal.h"

static void	pf_get_ddi(t_pf *pf)
{
	if (pf->ch == 'D')
		pf->flags |= LONGINT;
	if (pf->flags & INTMAX_SIZE)
	{
		pf->ujval = sjarg(pf, pf->flags);
		if ((intmax_t)pf->ujval < 0)
		{
			pf->ujval = -pf->ujval;
			pf->sign = '-';
		}
	}
	else
	{
		pf->ulval = sarg(pf, pf->flags);
		if ((long)pf->ulval < 0)
		{
			pf->ulval = -pf->ulval;
			pf->sign = '-';
		}
	}
	pf->base = 10;
	pf_number(pf);
}

static void	pf_get_oo(t_pf *pf)
{
	if (pf->ch == 'O')
		pf->flags |= LONGINT;
	if (pf->flags & INTMAX_SIZE)
		pf->ujval = ujarg(pf, pf->flags);
	else
		pf->ulval = uarg(pf, pf->flags);
	pf->base = 8;
	pf_nosign(pf);
}

static void	pf_get_uu(t_pf *pf)
{
	if (pf->ch == 'U')
		pf->flags |= LONGINT;
	if (pf->flags & INTMAX_SIZE)
		pf->ujval = ujarg(pf, pf->flags);
	else
		pf->ulval = uarg(pf, pf->flags);
	pf->base = 10;
	pf_nosign(pf);
}

static void	pf_get_xx(t_pf *pf)
{
	pf->xdigs = (pf->ch == 'X' ? XDIGS_UPPER : XDIGS_LOWER);
	if (pf->flags & INTMAX_SIZE)
		pf->ujval = ujarg(pf, pf->flags);
	else
		pf->ulval = uarg(pf, pf->flags);
	pf->base = 16;
	if (pf->flags & ALT \
		&& (pf->flags & INTMAX_SIZE ? pf->ujval != 0 : pf->ulval != 0))
		pf->ox[1] = pf->ch;
	pf_nosign(pf);
}

void		pf_parse_type(t_pf *pf)
{
	if (pf->ch == 'C' || pf->ch == 'c')
		pf_get_cc(pf);
	else if (pf->ch == 'D' || pf->ch == 'd' || pf->ch == 'i')
		pf_get_ddi(pf);
	else if (pf->ch == 'O' || pf->ch == 'o')
		pf_get_oo(pf);
	else if (pf->ch == 'p')
		pf_get_p(pf);
	else if (pf->ch == 'S' || pf->ch == 's')
		pf_get_ss(pf);
	else if (pf->ch == 'U' || pf->ch == 'u')
		pf_get_uu(pf);
	else if (pf->ch == 'X' || pf->ch == 'x')
		pf_get_xx(pf);
	else if (pf->ch == 'n')
		pf_set_n(pf);
}
