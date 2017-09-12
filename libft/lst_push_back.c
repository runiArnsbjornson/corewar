/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_push_back.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewen <yewen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 13:30:38 by yewen             #+#    #+#             */
/*   Updated: 2017/02/09 10:50:47 by yewen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lst.h"

void	lst_push_back(t_lst *lst, void *data)
{
	t_lst_node	*node;
	t_lst_node	*tmp;

	if ((node = malloc(sizeof(*node))) == NULL)
		return ;
	node->data = data;
	node->prev = NULL;
	node->next = NULL;
	if (lst->head == NULL)
		lst->head = node;
	else
	{
		tmp = lst->head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = node;
		node->prev = tmp;
	}
	++lst->count;
}
