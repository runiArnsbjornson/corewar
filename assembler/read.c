/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewen <yewen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 19:19:46 by yewen             #+#    #+#             */
/*   Updated: 2017/08/18 13:05:32 by yewen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "asm.h"

static char	*asm_read_helper(t_lst *lst, t_asm *a)
{
	int	i;

	a->n_lines = lst->count;
	lst_reverse(lst);
	if (!(a->lines = malloc(sizeof(char*) * lst->count)))
	{
		lst_destroy(lst);
		return ("Malloc error");
	}
	i = 0;
	while (i != a->n_lines)
		a->lines[i++] = lst_pop(lst);
	lst_destroy(lst);
	return (NULL);
}

char		*asm_read(const int fd, t_asm *a)
{
	char	*line;
	char	*tmp;
	t_lst	*lst;

	lst = lst_init(NULL, free);
	while (get_next_line(fd, &line) == 1)
	{
		tmp = line;
		line = ft_strtrim(line);
		free(tmp);
		if (*line != '\0' && *line != COMMENT_CHAR)
			lst_push(lst, line);
		else
			free(line);
	}
	if (lst->count < 3)
	{
		lst_destroy(lst);
		return ("File must contain at least 3 lines");
	}
	return (asm_read_helper(lst, a));
}
