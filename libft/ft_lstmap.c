/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewen <yewen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 20:36:59 by yewen             #+#    #+#             */
/*   Updated: 2016/04/28 22:17:16 by yewen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_lst;

	new_lst = (*f)(lst);
	if (new_lst != NULL && lst->next != NULL)
		new_lst->next = ft_lstmap(lst->next, f);
	return (new_lst);
}
