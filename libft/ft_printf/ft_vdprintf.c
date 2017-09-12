/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewen <yewen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 20:05:01 by yewen             #+#    #+#             */
/*   Updated: 2017/07/09 22:00:43 by yewen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "printflocal.h"

static void	pf_init0(t_pf *pf, int fd, const char *fmt, va_list ap)
{
	ft_bzero(pf, sizeof(*pf));
	pf->fd = fd;
	pf->fmt = (char *)fmt;
	va_copy(pf->ap, ap);
}

void		pf_init1(t_pf *pf)
{
	pf->flags = 0;
	pf->dprec = 0;
	pf->width = 0;
	pf->prec = -1;
	pf->sign = '\0';
	pf->ox[1] = '\0';
	pf->ch = *pf->fmt++;
}

static int	pf_flush(t_pf *pf)
{
	va_end(pf->ap);
	if (pf->convbuf != NULL)
		free(pf->convbuf);
	return (pf->ret);
}

int			ft_vdprintf(int fd, const char *fmt, va_list ap)
{
	t_pf	pf;

	pf_init0(&pf, fd, fmt, ap);
	while (1)
	{
		pf.cp = pf.fmt;
		while ((pf.ch = *pf.fmt) != '\0' && pf.ch != '%')
			++pf.fmt;
		if ((pf.n = pf.fmt - pf.cp) != 0)
			pf_raw_string(&pf);
		if (pf.ret == EOF || pf.ch == '\0')
			break ;
		++pf.fmt;
		pf_init1(&pf);
		pf_parse(&pf);
		if (pf.ch == '\0')
			break ;
		else if (pf.ch == 'n')
			continue ;
		pf_print(&pf);
		if (pf.ret == EOF)
			break ;
	}
	return (pf_flush(&pf));
}
