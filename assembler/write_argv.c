/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnaceur <abnaceur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 04:45:02 by abnaceur          #+#    #+#             */
/*   Updated: 2017/08/23 00:24:54 by yewen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "asm.h"

static void	write_register(char *data, int fd, int *cursor)
{
	ft_putchar_fd(ft_atoi(data), fd);
	++*cursor;
}

static long	fetch_code(t_asm *a, char *str, int ins_cursor)
{
	int		i;
	char	*name;
	t_label	*label;

	i = 0;
	while (str[i] && str[i] != SEPARATOR_CHAR)
		++i;
	name = ft_strsub(str, 1, i - 1);
	label = rb_search(a->labels, name);
	free(name);
	return (label->first_byte - ins_cursor);
}

static void	write_direct(t_asm *a, char *cell, t_write *w, int fd)
{
	int		i;
	long	n;
	long	code;

	if (cell[1] != LABEL_CHAR)
		code = w->op.dir_size \
			? ft_atoi(cell + 1) % 0x10000 : ft_atoi(cell + 1) % 0x100000000;
	else
		code = fetch_code(a, cell + 1, w->instruction_cursor);
	if (code < 0)
		code += w->op.dir_size ? 0x10000 : 0x100000000;
	i = 1;
	n = code;
	while (n / 0x100 && i++)
		n /= 0x100;
	n = i;
	i = 0;
	while (i < 2 + 2 * (1 - w->op.dir_size) - n)
	{
		ft_putchar_fd(0, fd);
		++i;
	}
	puthex_fd(code, fd);
	w->cursor += w->op.dir_size ? 2 : 4;
}

static void	write_indirect(t_asm *a, char *str, t_write *w, int fd)
{
	long	code;

	if (*str == LABEL_CHAR)
		code = fetch_code(a, str, w->instruction_cursor);
	else
		code = ft_atoi(str) % 0x10000;
	code = code > 0 ? code : 0x10000 + code;
	ft_putchar_fd(code / 256, fd);
	ft_putchar_fd(code % 256, fd);
	w->cursor += 2;
}

void		write_argv(t_asm *a, t_write *w, char *argv, int fd)
{
	int				i;
	int				count;

	i = 0;
	count = 0;
	while (count < w->op.argc)
	{
		if (argv[i] == 'r')
			write_register(argv + i + 1, fd, &w->cursor);
		else if (argv[i] == DIRECT_CHAR)
			write_direct(a, argv + i, w, fd);
		else
			write_indirect(a, argv + i, w, fd);
		while (argv[i] && argv[i] != SEPARATOR_CHAR)
			++i;
		++i;
		while (FT_ISSPACE(argv[i]))
			++i;
		++count;
	}
}
