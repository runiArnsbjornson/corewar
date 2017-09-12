/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewen <yewen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 12:43:43 by yewen             #+#    #+#             */
/*   Updated: 2017/08/20 18:38:38 by yewen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "corewar.h"

t_header	empty_head(void)
{
	t_header	head;

	ft_bzero(&head, sizeof(t_header));
	return (head);
}

void		proc_set(t_proc *p, int state)
{
	static t_arena	*a = NULL;

	if (!a)
		a = p->arena;
	if (state == SET_PLAYER)
		a->mem[p->pc] |= 1 << p->player;
	else
		a->mem[p->pc] &= (-1) & ~(1 << p->player);
}

int			err(const char *format, ...)
{
	va_list		va;

	va_start(va, format);
	ft_vdprintf(2, format, va);
	va_end(va);
	return (-1);
}

void		dump(uint8_t mem[], int mod)
{
	int		i;

	i = 0;
	while (i < MEM_SIZE)
	{
		if (!(i % mod))
			ft_printf(i ? "%#.4x : " : "0x%.4x : ", i);
		ft_printf("%x%x%s", mem[i] >> 4, mem[i] & 0xf, (i + 1) % mod ? " " :
			"\n");
		++i;
	}
}
