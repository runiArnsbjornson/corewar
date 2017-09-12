/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wstostr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewen <yewen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 15:30:03 by yewen             #+#    #+#             */
/*   Updated: 2017/04/23 12:43:53 by yewen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printflocal.h"

char		*wstostr(wchar_t *wstr)
{
	char	tmp[5];
	int		csize;
	char	*cp;

	cp = ft_strnew(sizeof(wchar_t) * ft_wcslen(wstr) + 1);
	while (*wstr)
	{
		wctostr(*wstr, tmp, &csize);
		ft_strcat(cp, tmp);
		++wstr;
	}
	return (cp);
}
