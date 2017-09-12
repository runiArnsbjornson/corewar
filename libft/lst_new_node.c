/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_new_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewen <yewen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/22 16:04:42 by yewen             #+#    #+#             */
/*   Updated: 2016/11/11 15:18:18 by yewen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_lst_node	*lst_new_node(void *data)
{
	t_lst_node	*node;

	if ((node = malloc(sizeof(*node))) == NULL)
		return (NULL);
	node->data = data;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}
