/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_instruction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewen <yewen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 01:13:46 by yewen             #+#    #+#             */
/*   Updated: 2017/08/21 22:17:50 by abnaceur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

extern const t_op g_op_tab[];

static int	write_opcode(char *op, int fd, int *cursor)
{
	int		id_ins;

	id_ins = fetch_op_id(op);
	ft_putchar_fd(id_ins, fd);
	++*cursor;
	return (id_ins);
}

static void	write_octal(t_op op, char *argv, int fd, int *cursor)
{
	unsigned char	octal;
	int				i;

	i = 0;
	octal = 0;
	while (i < op.argc)
	{
		if (argv[0] == 'r')
			octal += REG_CODE << ((3 - i) * 2);
		else if (argv[0] == DIRECT_CHAR)
			octal += DIR_CODE << ((3 - i) * 2);
		else
			octal += IND_CODE << ((3 - i) * 2);
		argv = ft_strchr(argv, SEPARATOR_CHAR) \
			? ft_strchr(argv, SEPARATOR_CHAR) + 1 : argv;
		if (*(argv - 1) == SEPARATOR_CHAR)
			while (FT_ISSPACE(*argv))
				++argv;
		++i;
	}
	ft_putchar_fd(octal, fd);
	++*cursor;
}

void		write_instruction(t_asm *a, int fd, int n_lines)
{
	int		i;
	t_write	w;

	ft_bzero(&w, sizeof(t_write));
	i = 2;
	w.cursor = -1;
	while (i < n_lines)
	{
		if (a->tlines[i]->label == 1)
		{
			++i;
			continue ;
		}
		w.id_ins = write_opcode(a->tlines[i]->op, fd, &w.cursor);
		w.instruction_cursor = w.cursor;
		w.op = g_op_tab[w.id_ins - 1];
		if (a->tlines[i]->label != 1 && w.op.octal)
			write_octal(w.op, a->tlines[i]->argv, fd, &w.cursor);
		write_argv(a, &w, a->tlines[i]->argv, fd);
		++i;
	}
}
