/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewen <yewen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 20:33:44 by yewen             #+#    #+#             */
/*   Updated: 2017/07/16 22:44:28 by yewen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int n)
{
	long int			ln;
	static const char	*charset = "0123456789";

	ln = n;
	if (ln < 0)
	{
		write(STDOUT_FILENO, "-", 1);
		ln = -ln;
	}
	if (ln > 9)
	{
		ft_putnbr(ln / 10);
		ft_putnbr(ln % 10);
	}
	else
		write(STDOUT_FILENO, charset + ln, 1);
}
