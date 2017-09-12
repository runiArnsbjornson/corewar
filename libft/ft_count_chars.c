/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_chars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewen <yewen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 11:26:01 by yewen             #+#    #+#             */
/*   Updated: 2017/07/11 11:27:20 by yewen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_chars(char *str, char c)
{
	int	ret;

	ret = 0;
	while (*str != '\0')
	{
		if (*str == c)
			++ret;
		++str;
	}
	return (ret);
}