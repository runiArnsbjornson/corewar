/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewen <yewen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 19:12:33 by yewen             #+#    #+#             */
/*   Updated: 2017/02/19 11:21:11 by yewen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

void	lst_rotate(t_lst *lst)
{
	t_lst_node	*node;
	t_lst_node	*tmp;

	node = lst->head;
	if (node == NULL)
		return ;
	if (node->next == NULL)
		return ;
	lst->head = node->next;
	lst->head->prev = NULL;
	tmp = lst->head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
	node->prev = tmp;
	node->next = NULL;
}
