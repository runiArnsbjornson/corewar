/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewen <yewen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 13:07:36 by yewen             #+#    #+#             */
/*   Updated: 2017/08/21 22:19:38 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_proc		*add_proc(t_arena *a, t_champ *c, int pc)
{
	t_proc	*proc;

	proc = try(sizeof(t_proc));
	proc->pc = pc;
	proc->id = ++a->proc_id;
	proc->get_inst = proc_read_inst;
	proc->get_params = proc_read_params;
	proc->reg[1] = (uint32_t)c->id;
	proc->arena = a;
	proc->op = NULL;
	proc->player = -c->id - 1;
	ft_pushback((void **)&a->procs, sizeof(t_proc *), a->proc_count++, &proc);
	a->alive++;
	return (proc);
}

t_proc		*fork_proc(t_arena *a, t_proc *p, int pc)
{
	t_proc	*proc;

	proc = try(sizeof(t_proc));
	proc->pc = pc;
	proc->id = ++a->proc_id;
	proc->oct = 0;
	proc->get_inst = proc_read_inst;
	proc->get_params = proc_read_params;
	ft_memcpy(proc->reg, p->reg, sizeof(p->reg));
	proc->arena = a;
	proc->op = NULL;
	proc->cycles_left = 0;
	proc->last_live = p->last_live;
	proc->carry = p->carry;
	proc->player = p->player;
	ft_pushback((void **)&a->procs, sizeof(t_proc *), a->proc_count++, &proc);
	a->alive++;
	return (proc);
}

static void	load_code(t_arena *a, t_champ *c)
{
	int		pc;
	t_proc	*p;

	pc = (-c->id - 1) * (MEM_SIZE / a->champ_count);
	p = add_proc(a, c, pc);
	ft_memcpy(a->arena + p->pc, c->source, c->head.prog_size);
	set_mem(a->mem, p->pc, c->head.prog_size, p->player);
	proc_set(p, SET_PLAYER);
}

static void	init_champ(t_arena *a, t_champ *c)
{
	if (!c->set)
	{
		c->num = ++a->max_n;
		c->set = 1;
	}
	load_code(a, c);
	ft_printf("* Player %d: weighing %d bytes, \"%s\" (\"%s\")\n", c->num, \
		c->head.prog_size, c->head.prog_name, c->head.comment);
}

void		init(t_arena *arena)
{
	int	i;

	arena->check = check_process;
	arena->add_proc = (t_f_add)add_proc;
	arena->ctd = CYCLE_TO_DIE;
	i = 0;
	ft_putstr("Introducing contestants...\n");
	while (i < arena->champ_count)
		init_champ(arena, arena->champs + i++);
	arena->add_proc = (t_f_add)fork_proc;
}
