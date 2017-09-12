/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewen <yewen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 21:38:23 by yewen             #+#    #+#             */
/*   Updated: 2017/02/19 18:17:53 by yewen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

void	lst_swap(t_lst *lst)
{
	t_lst_node	*node;

	if (lst->head == NULL)
		return ;
	if (lst->head->next == NULL)
		return ;
	node = lst->head;
	lst->head = node->next;
	node->prev = lst->head;
	node->next = lst->head->next;
	lst->head->prev = NULL;
	lst->head->next = node;
	if (node->next != NULL)
		node->next->prev = node;
}
