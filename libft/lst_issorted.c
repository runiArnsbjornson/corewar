/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_issorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewen <yewen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 17:05:42 by yewen             #+#    #+#             */
/*   Updated: 2017/02/05 17:11:52 by yewen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

int	lst_issorted(t_lst *lst)
{
	t_lst_node	*node;

	node = lst->head;
	if (node == NULL)
		return (1);
	while (node->next != NULL && lst->cmp(node->data, node->next->data) <= 0)
		node = node->next;
	if (node->next == NULL)
		return (1);
	return (0);
}
