/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_reverse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewen <yewen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 19:56:28 by yewen             #+#    #+#             */
/*   Updated: 2016/11/19 19:56:28 by yewen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

void	lst_reverse(t_lst *lst)
{
	t_lst_node	*curr;
	t_lst_node	*prev;
	t_lst_node	*next;

	curr = lst->head;
	prev = NULL;
	next = NULL;
	while (curr != NULL)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	lst->head = prev;
}
