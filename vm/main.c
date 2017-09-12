/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 10:16:12 by jdebladi          #+#    #+#             */
/*   Updated: 2017/08/23 12:24:41 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "corewar.h"

static void	free_arena(t_arena *a)
{
	int	i;

	if (a->champs)
	{
		i = 0;
		while (i < a->champ_count)
			if (a->champs[i].source)
				free(a->champs[i++].source);
		free(a->champs);
	}
	if (a->procs)
	{
		i = 0;
		while (i < a->proc_count)
			if (a->procs[i])
				free(a->procs[i++]);
		free(a->procs);
	}
}

int			loop(t_arena *a)
{
	int			i;

	i = a->proc_count;
	update_mem(a->mem);
	++a->cycles;
	if (a->verbose_lvl & V_LVL_CYCLES)
		ft_printf("Now it is cycle %d\n", a->cycles);
	while (--i >= 0)
		if (!a->procs[i]->dead)
			proc_exec_inst(a->procs[i]);
	if (a->cycles >= a->last_check + a->ctd)
		a->check(a);
	if (a->dump_cycles && a->cycles % a->dump_cycles == 0)
	{
		if (!(a->opts & S_OPT) && !a->cycles)
			return (0);
		dump(a->arena, DUMP_64);
		if (a->opts & S_OPT)
			while (read(0, &i, 1) && ((i ^ '\n') & 0xFF))
				;
		if (a->opts & D_OPT)
			return (0);
	}
	return (a->alive != 0);
}

static int	usage(char *s)
{
	const char	*str[] = {
		"[-dump N -s N -v N] [-a] [[-n N] <champion1.cor>] <...>\n",
		" -a           : Print output from \"aff\"",
		"(Default is to hide it)\n",
		"#### TEXT OUTPUT MODE ####################",
		"######################################\n",
		" -d (-dump) N : Dumps memory after N cycles then exits\n",
		" -s N         : Runs N cycles, dumps memory, pauses, then repeats\n",
		" -v N         : Verbosity levels, ",
		"can be added together to enable several\n",
		"                - 0  : Show only essentials\n",
		"                - 1  : Show lives\n",
		"                - 2  : Show cycles\n",
		"                - 4  : Show operations ",
		"(Params are NOT litteral ...)\n",
		"                - 8  : Show deaths\n",
		"                - 16 : Show PC movements (Except for jumps)\n",
		0};
	int			i;

	i = 0;
	ft_dprintf(2, "usage: %s ", s);
	while (str[i])
		ft_putstr_fd(str[i++], 2);
	return (1);
}

void		winner(t_arena *arena)
{
	int	i;
	int	w;

	i = 0;
	w = -1;
	if (arena->opts & A_OPT)
		ft_printf("aff buffer: %s\n", arena->aff);
	while (i < arena->champ_count)
	{
		if (w == -1 || arena->champs[i].last_live > arena->champs[w].last_live)
			w = i;
		++i;
	}
	if (w != -1)
		ft_printf("Contestant %d, \"%s\", has won!\n", \
			arena->champs[w].num, arena->champs[w].head.prog_name);
}

int			main(int argc, char *argv[])
{
	t_arena	arena;
	char	*err_msg;

	if (argc == 1)
		return (usage(argv[0]));
	ft_bzero(&arena, sizeof(t_arena));
	if ((err_msg = parse_arg(&arena, argc, argv)))
	{
		ft_dprintf(2, "%s: %s\n", *argv, err_msg);
		return (1);
	}
	if (!arena.champ_count)
	{
		ft_dprintf(2, "%s: No champion\n", *argv);
		return (1);
	}
	init(&arena);
	while (loop(&arena))
		;
	if (!(arena.opts & D_OPT))
		winner(&arena);
	free_arena(&arena);
	return (0);
}
