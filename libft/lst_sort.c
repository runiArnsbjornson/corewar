/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewen <yewen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 20:24:28 by yewen             #+#    #+#             */
/*   Updated: 2016/12/10 23:12:40 by yewen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

static t_lst_node	*split(t_lst_node *head)
{
	t_lst_node	*fast;
	t_lst_node	*slow;
	t_lst_node	*tmp;

	fast = head;
	slow = head;
	while (fast->next && fast->next->next)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	tmp = slow->next;
	slow->next = NULL;
	return (tmp);
}

static t_lst_node	*merge(t_lst_node *first, t_lst_node *second, int (*cmp)())
{
	if (!first)
		return (second);
	if (!second)
		return (first);
	if (cmp(first->data, second->data) < 0)
	{
		first->next = merge(first->next, second, cmp);
		first->next->prev = first;
		first->prev = NULL;
		return (first);
	}
	else
	{
		second->next = merge(first, second->next, cmp);
		second->next->prev = second;
		second->prev = NULL;
		return (second);
	}
}

static t_lst_node	*merge_sort(t_lst_node *head, int (*cmp)())
{
	t_lst_node	*second;

	if (!head || !head->next)
		return (head);
	second = split(head);
	head = merge_sort(head, cmp);
	second = merge_sort(second, cmp);
	return (merge(head, second, cmp));
}

void				lst_sort(t_lst *lst)
{
	lst->head = merge_sort(lst->head, lst->cmp);
}
