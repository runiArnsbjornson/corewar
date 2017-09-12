/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnaceur <abnaceur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 01:19:57 by abnaceur          #+#    #+#             */
/*   Updated: 2017/08/21 22:17:11 by abnaceur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "asm.h"

static char	*asm_parse(t_asm *a)
{
	char	*err_msg;

	if ((err_msg = parse_header(a)))
		return (err_msg);
	if ((err_msg = parse_line(a)))
		return (err_msg);
	return (NULL);
}

static void	free_tlines(t_asm *a)
{
	int	i;

	i = 2;
	while (i != a->n_lines)
	{
		if (a->tlines[i])
		{
			if (a->tlines[i]->op)
				free(a->tlines[i]->op);
			if (a->tlines[i]->argv)
				free(a->tlines[i]->argv);
		}
		else
			break ;
		free(a->tlines[i]);
		++i;
	}
	free(a->tlines);
}

static void	asm_free(t_asm *a)
{
	int	i;

	if (a->lines)
	{
		i = 0;
		while (i != a->n_lines)
			free(a->lines[i++]);
		free(a->lines);
	}
	if (a->tlines)
		free_tlines(a);
	if (a->header)
		free(a->header);
	if (a->labels)
		rb_destroy(a->labels);
}

static char	*run_helper(t_asm *a)
{
	char	*err_msg;

	if ((err_msg = asm_parse(a)))
	{
		asm_free(a);
		return (err_msg);
	}
	if ((err_msg = write_file(a, a->n_lines, a->header)))
	{
		asm_free(a);
		return (err_msg);
	}
	asm_free(a);
	return (NULL);
}

char		*run(char *file)
{
	int		fd;
	char	*err_msg;
	t_asm	a;

	if ((fd = open(file, O_RDONLY)) == -1)
		return ("open error");
	ft_bzero(&a, sizeof(a));
	a.file = file;
	if ((err_msg = asm_read(fd, &a)))
	{
		close(fd);
		asm_free(&a);
		return (err_msg);
	}
	close(fd);
	return (run_helper(&a));
}
