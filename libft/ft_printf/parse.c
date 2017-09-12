/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewen <yewen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 16:07:46 by yewen             #+#    #+#             */
/*   Updated: 2017/07/09 21:59:56 by yewen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "printflocal.h"

static void	pf_parse_default(t_pf *pf)
{
	pf->cp = pf->buf;
	*pf->cp = pf->ch;
	pf->size = 1;
	pf->sign = '\0';
}

void		pf_parse(t_pf *pf)
{
	while (1)
	{
		if (pf->ch != '\0' && ft_strchr(FLAGS, pf->ch))
		{
			pf_parse_flags(pf);
			continue ;
		}
		if (pf->ch == '.' || (pf->ch >= '1' && pf->ch <= '9'))
		{
			pf_parse_precision_width(pf);
			continue ;
		}
		if (pf->ch != '\0' && ft_strchr(MOD, pf->ch))
		{
			pf_parse_mod(pf);
			continue ;
		}
		if (pf->ch != '\0' && ft_strchr(TYPES, pf->ch))
			return (pf_parse_type(pf));
		if (pf->ch == '\0')
			return ;
		pf_parse_default(pf);
		return ;
	}
}
