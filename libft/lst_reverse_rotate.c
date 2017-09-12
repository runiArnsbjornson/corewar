/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_reverse_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewen <yewen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 20:48:25 by yewen             #+#    #+#             */
/*   Updated: 2017/02/19 11:21:59 by yewen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

void	lst_reverse_rotate(t_lst *lst)
{
	t_lst_node	*node;

	node = lst->head;
	if (node == NULL)
		return ;
	if (node->next == NULL)
		return ;
	while (node->next)
		node = node->next;
	node->prev->next = NULL;
	lst->head->prev = node;
	node->next = lst->head;
	lst->head = node;
	node->prev = NULL;
}
