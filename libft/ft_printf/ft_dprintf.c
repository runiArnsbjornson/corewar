/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewen <yewen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 09:47:25 by yewen             #+#    #+#             */
/*   Updated: 2017/02/07 09:49:43 by yewen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printflocal.h"

int	ft_dprintf(int fd, const char *fmt, ...)
{
	int		ret;
	va_list	ap;

	va_start(ap, fmt);
	ret = ft_vdprintf(fd, fmt, ap);
	va_end(ap);
	return (ret);
}
