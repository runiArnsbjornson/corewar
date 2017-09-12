/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewen <yewen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 16:06:09 by yewen             #+#    #+#             */
/*   Updated: 2017/02/07 09:45:07 by yewen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printflocal.h"

void	pf_parse_flags(t_pf *pf)
{
	if (pf->ch == ' ' && pf->sign == '\0')
		pf->sign = ' ';
	else if (pf->ch == '#')
		pf->flags |= ALT;
	else if (pf->ch == '*' || pf->ch == '-')
	{
		if (pf->ch == '*')
		{
			getaster(pf, &pf->width);
			if (pf->width >= 0)
			{
				pf->ch = *pf->fmt++;
				return ;
			}
			pf->width = -pf->width;
		}
		pf->flags |= LADJUST;
	}
	else if (pf->ch == '+')
		pf->sign = '+';
	else if (pf->ch == '0')
		pf->flags |= ZEROPAD;
	pf->ch = *pf->fmt++;
}

void	pf_parse_precision_width(t_pf *pf)
{
	if (pf->ch == '.')
	{
		if ((pf->ch = *pf->fmt++) == '*')
		{
			getaster(pf, &pf->prec);
			pf->ch = *pf->fmt++;
			return ;
		}
		pf->prec = 0;
		while (FT_ISDIGIT(pf->ch))
		{
			pf->prec = 10 * pf->prec + FT_TODIGIT(pf->ch);
			pf->ch = *pf->fmt++;
		}
		return ;
	}
	pf->n = 0;
	pf->n = 10 * pf->n + FT_TODIGIT(pf->ch);
	pf->ch = *pf->fmt++;
	while (FT_ISDIGIT(pf->ch))
	{
		pf->n = 10 * pf->n + FT_TODIGIT(pf->ch);
		pf->ch = *pf->fmt++;
	}
	pf->width = pf->n;
}

void	pf_parse_mod(t_pf *pf)
{
	if (pf->ch == 'h')
	{
		if (pf->flags & SHORTINT)
		{
			pf->flags &= ~SHORTINT;
			pf->flags |= CHARINT;
		}
		else
			pf->flags |= SHORTINT;
	}
	else if (pf->ch == 'j')
		pf->flags |= INTMAXT;
	else if (pf->ch == 'l')
	{
		if (pf->flags & LONGINT)
		{
			pf->flags &= ~LONGINT;
			pf->flags |= LLONGINT;
		}
		else
			pf->flags |= LONGINT;
	}
	else if (pf->ch == 'z')
		pf->flags |= SIZET;
	pf->ch = *pf->fmt++;
}
