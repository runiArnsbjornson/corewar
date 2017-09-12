/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewen <yewen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 00:02:06 by yewen             #+#    #+#             */
/*   Updated: 2017/08/19 15:43:00 by yewen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ARRAY_H
# define FT_ARRAY_H

typedef struct	s_array
{
	void	*t;
	size_t	size;
	int		n;
}				t_array;

t_array			ft_array(void *t, size_t size, int n);
void			*ft_array_find(t_array t, void *ref, int (*f)());

#endif
