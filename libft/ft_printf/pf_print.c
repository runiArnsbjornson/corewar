/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewen <yewen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 02:13:44 by yewen             #+#    #+#             */
/*   Updated: 2017/02/07 09:52:51 by yewen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "printflocal.h"

static void	pad(int fd, int howmany, const char *with)
{
	int	n;

	while (howmany > 0)
	{
		n = (howmany >= PADSIZE) ? PADSIZE : howmany;
		write(fd, with, n);
		howmany -= n;
	}
}

static void	pf_print_helper(t_pf *pf)
{
	pf->realsz = pf->dprec > pf->size ? pf->dprec : pf->size;
	if (pf->sign)
		++pf->realsz;
	if (pf->ox[1])
		pf->realsz += 2;
	pf->prsize = pf->width > pf->realsz ? pf->width : pf->realsz;
}

void		pf_raw_string(t_pf *pf)
{
	if ((unsigned)pf->ret + pf->n > INT_MAX)
	{
		pf->ret = EOF;
		return ;
	}
	write(pf->fd, pf->cp, pf->n);
	pf->ret += pf->n;
}

void		pf_print(t_pf *pf)
{
	static const char	blanks[PADSIZE] = BLKS;
	static const char	zeroes[PADSIZE] = ZERO;

	pf_print_helper(pf);
	if ((unsigned)pf->ret + pf->prsize > INT_MAX)
	{
		pf->ret = EOF;
		return ;
	}
	if ((pf->flags & (LADJUST | ZEROPAD)) == 0)
		pad(pf->fd, pf->width - pf->realsz, blanks);
	if (pf->sign)
		write(pf->fd, &pf->sign, 1);
	if (pf->ox[1])
	{
		pf->ox[0] = '0';
		write(pf->fd, pf->ox, 2);
	}
	if ((pf->flags & (LADJUST | ZEROPAD)) == ZEROPAD)
		pad(pf->fd, pf->width - pf->realsz, zeroes);
	pad(pf->fd, pf->dprec - pf->size, zeroes);
	write(pf->fd, pf->cp, pf->size);
	if (pf->flags & LADJUST)
		pad(pf->fd, pf->width - pf->realsz, blanks);
	pf->ret += pf->prsize;
}
