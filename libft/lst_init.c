/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewen <yewen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/22 15:24:22 by yewen             #+#    #+#             */
/*   Updated: 2017/02/17 23:41:58 by yewen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_lst	*lst_init(int (*cmp)(), void (*delfn)())
{
	t_lst	*lst;

	if ((lst = malloc(sizeof(*lst))) == NULL)
		return (NULL);
	ft_bzero(lst, sizeof(*lst));
	lst->head = NULL;
	lst->count = 0;
	lst->cmp = cmp;
	lst->delfn = delfn;
	return (lst);
}
