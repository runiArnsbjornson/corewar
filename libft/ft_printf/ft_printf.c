/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewen <yewen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 09:38:49 by yewen             #+#    #+#             */
/*   Updated: 2017/02/07 09:38:49 by yewen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printflocal.h"

int	ft_printf(const char *fmt, ...)
{
	int		ret;
	va_list	ap;

	va_start(ap, fmt);
	ret = ft_vdprintf(STDOUT_FILENO, fmt, ap);
	va_end(ap);
	return (ret);
}
