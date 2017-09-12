/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewen <yewen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 16:21:17 by yewen             #+#    #+#             */
/*   Updated: 2017/02/07 09:45:48 by yewen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printflocal.h"

void	pf_number(t_pf *pf)
{
	if ((pf->dprec = pf->prec) >= 0)
		pf->flags &= ~ZEROPAD;
	pf->cp = pf->buf + BUF;
	if (pf->flags & INTMAX_SIZE)
	{
		if (pf->ujval != 0 || pf->prec != 0 \
			|| (pf->flags & ALT && pf->base == 8))
			pf->cp = ujtoa(pf, pf->ujval, pf->cp);
	}
	else
	{
		if (pf->ulval != 0 || pf->prec != 0 \
			|| (pf->flags & ALT && pf->base == 8))
			pf->cp = ultoa(pf, pf->ulval, pf->cp);
	}
	pf->size = pf->buf + BUF - pf->cp;
}

void	pf_nosign(t_pf *pf)
{
	pf->sign = '\0';
	pf_number(pf);
}
