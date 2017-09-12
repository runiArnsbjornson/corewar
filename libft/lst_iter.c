/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_iter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewen <yewen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 21:54:39 by yewen             #+#    #+#             */
/*   Updated: 2017/02/07 21:56:27 by yewen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

void	lst_iter(t_lst *lst, void (*fn)())
{
	t_lst_node	*node;

	node = lst->head;
	while (node)
	{
		fn(node);
		node = node->next;
	}
}
