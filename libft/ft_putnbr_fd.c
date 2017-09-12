/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewen <yewen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 20:33:53 by yewen             #+#    #+#             */
/*   Updated: 2016/07/16 16:00:35 by yewen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	long int			ln;
	static const char	*charset = "0123456789";

	ln = n;
	if (ln < 0)
	{
		write(fd, "-", 1);
		ln = -ln;
	}
	if (ln > 9)
	{
		ft_putnbr_fd(ln / 10, fd);
		ft_putnbr_fd(ln % 10, fd);
	}
	else
		write(fd, charset + ln, 1);
}
