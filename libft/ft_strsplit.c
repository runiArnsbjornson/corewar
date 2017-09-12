/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewen <yewen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 20:49:58 by yewen             #+#    #+#             */
/*   Updated: 2016/05/17 08:59:30 by yewen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int		word_count(const char *s, char c)
{
	int	n;

	n = 0;
	while (*s != '\0')
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
			++n;
		++s;
	}
	return (n);
}

static size_t	word_len(const char *s, char c)
{
	const char	*ptr;

	ptr = s;
	while (*ptr != c && *ptr != '\0')
		++ptr;
	return (ptr - s);
}

static void		fill_tab(char **tab, const char *s, char c)
{
	size_t	len;

	while (*s != '\0')
	{
		if (*s != c)
		{
			len = word_len(s, c);
			if ((*tab = malloc(len + 1)) == NULL)
				return ;
			ft_strncpy(*tab, s, len);
			*(*tab++ + len) = '\0';
			s += len;
		}
		else
			++s;
	}
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		n;

	n = word_count(s, c);
	if ((tab = malloc(sizeof(*tab) * (n + 1))) == NULL)
		return (NULL);
	fill_tab(tab, s, c);
	*(tab + n) = NULL;
	return (tab);
}
