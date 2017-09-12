/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_insert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewen <yewen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 10:05:31 by yewen             #+#    #+#             */
/*   Updated: 2016/11/11 12:59:42 by yewen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

void	lst_insert(t_lst *lst, t_lst_node *node)
{
	node->next = lst->head;
	if (lst->head != NULL)
		lst->head->prev = node;
	lst->head = node;
	node->prev = NULL;
	++lst->count;
}
