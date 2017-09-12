/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_search.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewen <yewen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 22:29:16 by yewen             #+#    #+#             */
/*   Updated: 2016/12/10 23:07:19 by yewen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

t_lst_node	*lst_search(t_lst *lst, void *data)
{
	t_lst_node	*node;

	node = lst->head;
	while (node != NULL)
	{
		if (lst->cmp(node->data, data) == 0)
			return (node);
		node = node->next;
	}
	return (NULL);
}
