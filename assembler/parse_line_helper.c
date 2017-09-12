/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line_helper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnaceur <abnaceur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 15:22:19 by abnaceur          #+#    #+#             */
/*   Updated: 2017/08/23 00:24:29 by yewen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "asm.h"

extern const t_op g_op_tab[];

char		*parse_fetch_op(char **line, t_line *tl)
{
	int		i;
	char	*ptr;

	ptr = *line;
	i = 0;
	while (ptr[i] && !FT_ISSPACE(ptr[i]))
		++i;
	tl->op = ft_strndup(ptr, i);
	ptr += i;
	*line = ptr;
	if (fetch_op_id(tl->op) == -1)
		return ("Unknown instruction or illegal character label");
	return (NULL);
}

static int	parse_check_argc(char *argv, t_op op)
{
	int	argc;

	argc = 1;
	while (*argv)
	{
		if (*argv == SEPARATOR_CHAR)
			++argc;
		++argv;
	}
	if (argc != op.argc)
		return (0);
	return (1);
}

static int	parse_check_arg(char *argv, t_op op, t_asm *a)
{
	int	i;
	int	p;

	if (!parse_check_argc(argv, op))
		return (0);
	i = 0;
	p = 0;
	while (argv[i] && p < op.argc)
	{
		if (argv[i] == 'r' && !check_register(argv + i, op, p))
			return (0);
		else if (argv[i] == DIRECT_CHAR && !check_direct(argv + i, op, p, a))
			return (0);
		else if (argv[i] != DIRECT_CHAR && argv[i] != 'r' \
			&& !check_indirect(argv + i, op, p, a))
			return (0);
		if (ft_strchr(argv + i, SEPARATOR_CHAR))
			i += ft_strchr(argv + i, SEPARATOR_CHAR) - (argv + i) + 1;
		while (FT_ISSPACE(argv[i]))
			++i;
		++p;
	}
	return (1);
}

char		*parse_fetch_argv(char *line, t_line *tl, t_asm *a)
{
	char	*ptr;

	if ((ptr = ft_strchr(line, COMMENT_CHAR)))
	{
		*ptr = '\0';
		tl->argv = ft_strdup(line);
		ptr = tl->argv;
		tl->argv = ft_strtrim(tl->argv);
		free(ptr);
	}
	else
		tl->argv = ft_strdup(line);
	if (!parse_check_arg(tl->argv, g_op_tab[fetch_op_id(tl->op) - 1], a))
		return ("Arguments syntax error");
	return (NULL);
}
