/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewen <yewen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 20:31:25 by yewen             #+#    #+#             */
/*   Updated: 2017/02/01 13:38:32 by yewen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int ret;
	int sign;

	while (FT_ISSPACE(*str))
		++str;
	sign = 1;
	if (*str == '-' || *str == '+')
		sign = *str++ == '-' ? -1 : 1;
	ret = 0;
	while (FT_ISDIGIT(*str))
		ret = ret * 10 + FT_TODIGIT(*str++);
	return (ret * sign);
}
