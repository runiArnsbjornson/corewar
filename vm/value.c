/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewen <yewen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 23:21:53 by yewen             #+#    #+#             */
/*   Updated: 2017/08/21 00:51:23 by yewen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_val	val(void *p, uint8_t s)
{
	return ((t_val){p, s});
}

int		wrap_size(int v, int size)
{
	if (size == 4)
		return (v);
	if (size == 2)
		return ((short)v);
	return ((char)v);
}

int		get_value(t_proc *p, int *v, int i, t_type type)
{
	*v = wrap_size(p->params[i], p->p_sizes[i]);
	if (p->p_types[i] == REG_CODE)
	{
		if (*v <= 0 || *v > REG_NUMBER)
			return (-1);
		*v = type == V_REFERENCE ? *v : p->reg[*v];
		return (0);
	}
	if (type == V_REFERENCE || p->p_types[i] == DIR_CODE)
		return (0);
	*v = mem_mod(type == V_VALUE_NOIDX ? p->pc + *v : idx_mod(p->pc, *v));
	read_mem(*v, val(v, sizeof(int)), p->arena->arena);
	return (0);
}

void	update_mem(uint32_t *mem)
{
	int			i;
	uint32_t	o;

	i = 0;
	while (i < MEM_SIZE)
	{
		if (mem[i] & 0xFFFF0000)
		{
			o = (mem[i] >> 16) - 1;
			mem[i] &= 0xFF;
			mem[i] |= o << 16;
		}
		++i;
	}
}
