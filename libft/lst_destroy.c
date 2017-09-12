/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewen <yewen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 16:42:31 by yewen             #+#    #+#             */
/*   Updated: 2016/12/10 23:04:16 by yewen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lst.h"

void	lst_destroy(t_lst *lst)
{
	void	*data;

	while ((data = lst_pop(lst)) != NULL)
		if (lst->delfn != NULL)
			lst->delfn(data);
	free(lst);
}
