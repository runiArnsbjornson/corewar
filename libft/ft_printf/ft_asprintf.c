/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewen <yewen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 23:43:08 by yewen             #+#    #+#             */
/*   Updated: 2017/07/14 01:04:35 by yewen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printflocal.h"

int	ft_asprintf(char **strp, const char *fmt, ...)
{
	int		ret;
	va_list	ap;

	va_start(ap, fmt);
	ret = ft_vasprintf(strp, fmt, ap);
	va_end(ap);
	return (ret);
}
