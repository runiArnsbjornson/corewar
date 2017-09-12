/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_champ.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 16:57:33 by jdebladi          #+#    #+#             */
/*   Updated: 2017/08/21 22:21:54 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include "libft.h"
#include "corewar.h"

static int		load_source(t_champ *c)
{
	int			fd;

	if ((fd = open(c->file_name, O_RDONLY)) == -1)
	{
		perror(c->file_name);
		return (1);
	}
	if (read(fd, &c->head, sizeof(t_header)) != sizeof(t_header))
		return (err("%s: Bad header or empty file\n", c->file_name));
	ft_endian(&c->head.prog_size, sizeof(c->head.prog_size));
	ft_endian(&c->head.magic, sizeof(c->head.magic));
	if (c->head.magic != COREWAR_EXEC_MAGIC)
		return (err("%s: Bad magic number\n", c->file_name));
	if (c->head.prog_size > CHAMP_MAX_SIZE)
	{
		return (err("File %s is too big (%d bytes > 682 bytes)\n", \
			c->file_name, c->head.prog_size));
	}
	c->source = try(c->head.prog_size);
	if (read(fd, c->source, c->head.prog_size) != c->head.prog_size)
		return (err("%s: Bad file\n", c->file_name));
	close(fd);
	return (0);
}

static int		parse_check_set(t_champ *champs, int count, int n)
{
	int		i;

	i = 0;
	while (i < count)
	{
		if (champs[i].set && champs[i].num == n)
			return (-1);
		++i;
	}
	return (0);
}

static t_champ	new_champion(char *name, char *number, t_arena *a)
{
	static int		id = 0;
	t_champ			c;
	int				ret;

	ft_bzero(&c, sizeof(t_champ));
	c.head = empty_head();
	c.file_name = name;
	if (load_source(&c))
	{
		ft_memdel((void **)&c.source);
		return (c);
	}
	if (number)
	{
		if (parse_check_set(a->champs, a->champ_count, (ret = ft_atoi(number))))
			err("Warning: Duplicate player number\n");
		else
		{
			c.set = 1;
			c.num = ret;
			a->max_n = ret > a->max_n ? ret : a->max_n;
		}
	}
	c.id = --id;
	return (c);
}

char			*player(t_arena *a, char *file, char *n)
{
	t_champ	c;

	c = new_champion(file, n, a);
	if (c.source == NULL)
		return ("Champion file error");
	if (a->champ_count >= 4)
		return ("Too many champion");
	else
		ft_pushback((void **)&a->champs, sizeof(t_champ), a->champ_count++, &c);
	return (NULL);
}
