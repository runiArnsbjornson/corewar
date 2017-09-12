/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aspf_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewen <yewen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 00:24:14 by yewen             #+#    #+#             */
/*   Updated: 2017/07/14 01:04:28 by yewen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "printflocal.h"

void		aspf_raw_string(t_pf *pf)
{
	if ((unsigned)pf->ret + pf->n > INT_MAX)
	{
		pf->ret = EOF;
		return ;
	}
	lst_push(pf->str, ft_strndup(pf->cp, pf->n));
	pf->ret += pf->n;
}

static void	aspf_pad(t_lst *str, int howmany, const char *with)
{
	int	n;

	while (howmany > 0)
	{
		n = (howmany >= PADSIZE) ? PADSIZE : howmany;
		lst_push(str, ft_strndup(with, n));
		howmany -= n;
	}
}

static void	aspf_print_helper(t_pf *pf)
{
	pf->realsz = pf->dprec > pf->size ? pf->dprec : pf->size;
	if (pf->sign)
		++pf->realsz;
	if (pf->ox[1])
		pf->realsz += 2;
	pf->prsize = pf->width > pf->realsz ? pf->width : pf->realsz;
}

void		aspf_print(t_pf *pf)
{
	static const char	blanks[PADSIZE] = BLKS;
	static const char	zeroes[PADSIZE] = ZERO;

	aspf_print_helper(pf);
	if ((unsigned)pf->ret + pf->prsize > INT_MAX)
	{
		pf->ret = EOF;
		return ;
	}
	if ((pf->flags & (LADJUST | ZEROPAD)) == 0)
		aspf_pad(pf->str, pf->width - pf->realsz, blanks);
	if (pf->sign)
		lst_push(pf->str, ft_strndup(&pf->sign, 1));
	if (pf->ox[1])
	{
		pf->ox[0] = '0';
		lst_push(pf->str, ft_strndup(pf->ox, 2));
	}
	if ((pf->flags & (LADJUST | ZEROPAD)) == ZEROPAD)
		aspf_pad(pf->str, pf->width - pf->realsz, zeroes);
	aspf_pad(pf->str, pf->dprec - pf->size, zeroes);
	lst_push(pf->str, ft_strndup(pf->cp, pf->size));
	if (pf->flags & LADJUST)
		aspf_pad(pf->str, pf->width - pf->realsz, blanks);
	pf->ret += pf->prsize;
}
