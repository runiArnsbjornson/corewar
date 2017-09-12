/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_pop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewen <yewen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 14:19:02 by yewen             #+#    #+#             */
/*   Updated: 2016/11/19 14:44:26 by yewen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lst.h"

void	*lst_pop(t_lst *lst)
{
	t_lst_node	*node;
	void		*data;

	if (lst->head == NULL)
		return (NULL);
	node = lst->head;
	data = node->data;
	lst->head = node->next;
	free(node);
	if (lst->head != NULL)
		lst->head->prev = NULL;
	--lst->count;
	return (data);
}
