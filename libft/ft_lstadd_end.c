/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewen <yewen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 14:22:56 by yewen             #+#    #+#             */
/*   Updated: 2017/08/17 14:22:56 by yewen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_end(t_list **alst, t_list *new)
{
	if (alst)
	{
		if (*alst == NULL)
			*alst = new;
		else
		{
			if ((*alst)->next)
				ft_lstadd_end(&((*alst)->next), new);
			else
				(*alst)->next = new;
		}
	}
}
