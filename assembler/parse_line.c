/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewen <yewen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 15:48:30 by yewen             #+#    #+#             */
/*   Updated: 2017/08/21 22:16:07 by abnaceur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "asm.h"

static char	*check_label(t_asm *a, char *line, int index)
{
	int		i;
	t_label	*l;
	char	*name;

	i = 0;
	while (line[i] != LABEL_CHAR)
	{
		if (!(ft_strchr(LABEL_CHARS, line[i])))
			return ("Illegal label character");
		++i;
	}
	name = ft_strndup(line, i);
	if (rb_search(a->labels, name))
	{
		free(name);
		return (NULL);
	}
	if (!(l = ft_memalloc(sizeof(*l))))
		return ("Malloc error\n");
	l->name = name;
	l->index = index;
	rb_insert(a->labels, l->name, l);
	return (NULL);
}

static char	*parse_label(t_asm *a, char **line)
{
	int	i;

	i = 2;
	a->labels = rb_init(ft_strcmp, free, free);
	while (i != a->n_lines)
	{
		if (ft_strchr(line[i], LABEL_CHAR))
			check_label(a, line[i], i);
		++i;
	}
	return (NULL);
}

static char	*parse_instruction(t_asm *a, char *line, int index)
{
	char	*err_msg;

	if (ft_strchr(line, LABEL_CHAR) && !check_label(a, line, index))
	{
		while (*line++ != LABEL_CHAR)
			;
		a->tlines[index]->label = 2;
	}
	while (*line && FT_ISSPACE(*line))
		++line;
	if ((err_msg = parse_fetch_op(&line, a->tlines[index])))
		return (err_msg);
	while (*line && FT_ISSPACE(*line))
		++line;
	if (*line == '\0')
		return ("Arguments syntax error");
	if ((err_msg = parse_fetch_argv(line, a->tlines[index], a)))
		return (err_msg);
	return (NULL);
}

char		*parse_line(t_asm *a)
{
	int		i;
	char	*err_msg;

	parse_label(a, a->lines);
	if (!(a->tlines = ft_memalloc(sizeof(t_line*) * a->n_lines)))
		return ("Malloc error");
	i = 2;
	while (i != a->n_lines)
	{
		if (!(a->tlines[i] = ft_memalloc(sizeof(t_line))))
			return ("Malloc error\n");
		if (a->lines[i][ft_strlen(a->lines[i]) - 1] == LABEL_CHAR)
		{
			if ((err_msg = check_label(a, a->lines[i], i)))
				return (err_msg);
			a->tlines[i]->label = 1;
		}
		else
		{
			if ((err_msg = parse_instruction(a, a->lines[i], i)))
				return (err_msg);
		}
		++i;
	}
	return (NULL);
}
