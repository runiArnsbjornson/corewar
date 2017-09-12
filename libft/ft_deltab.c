/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deltab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewen <yewen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 14:13:29 by yewen             #+#    #+#             */
/*   Updated: 2017/08/17 14:13:29 by yewen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_deltab(char **tab)
{
	char **cpy;

	cpy = tab;
	while (*tab)
		ft_memdel((void **)tab++);
	ft_memdel((void **)&cpy);
}
