/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnaceur <abnaceur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 02:21:56 by abnaceur          #+#    #+#             */
/*   Updated: 2017/08/23 08:58:23 by yewen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "asm.h"

extern const t_op g_op_tab[];

static void	set_label_helper(t_asm *a, int *i, int *count)
{
	char	*label;
	t_label	*tlabel;
	char	*ptr;

	label = ft_strdup(a->lines[*i]);
	ptr = ft_strchr(label, LABEL_CHAR);
	*ptr = '\0';
	tlabel = rb_search(a->labels, label);
	free(label);
	tlabel->first_byte = *count;
}

static void	set_label_ins(t_asm *a, int i, int *count)
{
	int		j;
	int		id_ins;
	int		argc;
	char	*argv;

	id_ins = fetch_op_id(a->tlines[i]->op);
	if (g_op_tab[id_ins - 1].octal)
		++*count;
	j = 0;
	argc = -1;
	argv = a->tlines[i]->argv;
	while (++argc < g_op_tab[id_ins - 1].argc)
	{
		if (argv[j] == 'r')
			++*count;
		else if (argv[j] == DIRECT_CHAR)
			*count += g_op_tab[id_ins - 1].dir_size ? 2 : 4;
		else
			*count += 2;
		while (argv[j] && argv[j] != SEPARATOR_CHAR)
			++j;
		++j;
		while (FT_ISSPACE(argv[j]))
			++j;
	}
}

int			set_label(t_asm *a)
{
	int	count;
	int	i;

	count = 0;
	i = 2;
	while (i != a->n_lines)
	{
		if (a->tlines[i]->label)
			set_label_helper(a, &i, &count);
		if (a->tlines[i]->label != 1)
		{
			++count;
			set_label_ins(a, i, &count);
		}
		++i;
	}
	return (count);
}
