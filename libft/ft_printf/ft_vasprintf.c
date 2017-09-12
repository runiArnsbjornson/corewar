/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vasprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewen <yewen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 23:50:08 by yewen             #+#    #+#             */
/*   Updated: 2017/07/14 01:04:42 by yewen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "printflocal.h"

static void	aspf_init0(t_pf *pf, const char *fmt, va_list ap)
{
	ft_bzero(pf, sizeof(*pf));
	pf->fmt = (char *)fmt;
	va_copy(pf->ap, ap);
	pf->str = lst_init(NULL, free);
}

static int	aspf_flush(t_pf *pf, char **strp)
{
	void	*data;

	va_end(pf->ap);
	if (pf->convbuf != NULL)
		free(pf->convbuf);
	if (pf->ret == EOF)
	{
		*strp = NULL;
		return (EOF);
	}
	if ((*strp = ft_memalloc(pf->ret + 1)) == NULL)
		return (EOF);
	lst_reverse(pf->str);
	while ((data = lst_pop(pf->str)) != NULL)
	{
		ft_strcat(*strp, data);
		free(data);
	}
	lst_destroy(pf->str);
	return (pf->ret);
}

int			ft_vasprintf(char **strp, const char *fmt, va_list ap)
{
	t_pf	pf;

	aspf_init0(&pf, fmt, ap);
	while (1)
	{
		pf.cp = pf.fmt;
		while ((pf.ch = *pf.fmt) != '\0' && pf.ch != '%')
			++pf.fmt;
		if ((pf.n = pf.fmt - pf.cp) != 0)
			aspf_raw_string(&pf);
		if (pf.ret == EOF || pf.ch == '\0')
			break ;
		++pf.fmt;
		pf_init1(&pf);
		pf_parse(&pf);
		if (pf.ch == '\0')
			break ;
		else if (pf.ch == 'n')
			continue ;
		aspf_print(&pf);
		if (pf.ret == EOF)
			break ;
	}
	return (aspf_flush(&pf, strp));
}
