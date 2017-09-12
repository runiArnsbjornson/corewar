/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_try.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewen <yewen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 13:49:40 by yewen             #+#    #+#             */
/*   Updated: 2017/08/17 13:51:54 by yewen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*try(size_t size)
{
	void	*p;

	if ((p = ft_memalloc(size)) == NULL)
		exit(EXIT_FAILURE);
	return (p);
}
