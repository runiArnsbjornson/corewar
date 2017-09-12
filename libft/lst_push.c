/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewen <yewen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 16:55:05 by yewen             #+#    #+#             */
/*   Updated: 2017/02/17 11:02:15 by yewen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lst.h"

void	lst_push(t_lst *lst, void *data)
{
	t_lst_node	*node;

	if (data == NULL)
		return ;
	if ((node = malloc(sizeof(*node))) == NULL)
		return ;
	node->data = data;
	node->next = lst->head;
	if (lst->head != NULL)
		lst->head->prev = node;
	lst->head = node;
	node->prev = NULL;
	++lst->count;
}
