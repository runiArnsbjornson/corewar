/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_delete.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewen <yewen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 13:04:53 by yewen             #+#    #+#             */
/*   Updated: 2016/12/10 23:03:03 by yewen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lst.h"

void	lst_delete(t_lst *lst, t_lst_node *node)
{
	if (node->prev != NULL)
		node->prev->next = node->next;
	else
		lst->head = node->next;
	if (node->next != NULL)
		node->next->prev = node->prev;
	if (lst->delfn != NULL)
		lst->delfn(node->data);
	free(node);
	--lst->count;
}
