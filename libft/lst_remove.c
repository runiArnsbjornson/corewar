/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_remove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewen <yewen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 14:17:10 by yewen             #+#    #+#             */
/*   Updated: 2016/12/10 23:06:12 by yewen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

void	lst_remove(t_lst *lst, void *data)
{
	t_lst_node	*node;

	node = lst_search(lst, data);
	while (node != NULL)
	{
		lst_delete(lst, node);
		node = lst_search(lst, data);
	}
}
