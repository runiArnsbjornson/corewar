/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewen <yewen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 21:43:49 by yewen             #+#    #+#             */
/*   Updated: 2017/08/21 22:22:24 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H
# include <stdint.h>
# include "libft.h"
# include "op.h"

# define CHAMP_FLAG_ID		0x01
# define PROC_CODE(o, i)	((o >> (2 * (3 - i))) & 3)
# define PROC_TYPE(o)		(1 << (o - 1))

# define V_OPT				0x01
# define A_OPT				0x02
# define D_OPT				0x04
# define S_OPT				0x08

# define DUMP_OUT			0x20
# define DUMP_64			0x40

# define V_LVL_LIVES		0x01
# define V_LVL_CYCLES		0x02
# define V_LVL_OP			0x04
# define V_LVL_DEATH		0x08
# define V_LVL_PC			0x10

# define UNSET_PLAYER		0x0
# define SET_PLAYER			0x1

extern t_op		g_op_tab[17];

struct s_champ;
struct s_proc;
struct s_arena;

typedef int				(*t_f_get)(struct s_proc *, uint8_t[]);
typedef int				(*t_f_fill)(struct s_proc *, uint8_t[]);
typedef void			(*t_f_filter)(struct s_arena *);
typedef struct s_proc	*(*t_f_add)(struct s_arena *, void *, int);

typedef enum	e_type
{
	V_VALUE,
	V_VALUE_NOIDX,
	V_REFERENCE
}				t_type;

typedef struct	s_val
{
	void	*p;
	uint8_t	s;
}				t_val;

typedef struct	s_champ
{
	char		*file_name;
	uint8_t		*source;
	t_header	head;
	int			id;
	int			num;
	int			set;
	int			nbr_live;
	int			last_live;
}				t_champ;

typedef struct	s_proc
{
	struct s_arena	*arena;
	unsigned int	reg[REG_NUMBER + 1];
	t_op			*op;
	t_f_get			get_inst;
	t_f_fill		get_params;
	uint32_t		params[MAX_ARGS_NUMBER];
	uint8_t			p_sizes[MAX_ARGS_NUMBER];
	uint8_t			p_types[MAX_ARGS_NUMBER];
	int				cycles_left;
	int				id;
	int				pc;
	int				carry;
	int				last_live;
	unsigned char	oct;
	int				player;
	int				dead;
}				t_proc;

typedef struct	s_arena
{
	t_champ		*champs;
	int			max_n;
	t_proc		**procs;
	uint8_t		arena[MEM_SIZE];
	uint32_t	mem[MEM_SIZE];
	t_f_add		add_proc;
	t_f_filter	check;
	char		*aff;
	int			champ_count;
	int			proc_count;
	int			proc_id;
	int			ctd;
	int			last_check;
	int			cycles;
	int			check_cycles;
	int			nbr_lives;
	int			dump_cycles;
	int			opts;
	int			alive;
	int			debug_fd;
	int			verbose_lvl;
}				t_arena;

char			*parse_arg(t_arena *a, int argc, char *argv[]);
char			*player(t_arena *a, char *file, char *n);

void			init(t_arena *a);

t_proc			*add_proc(t_arena *a, t_champ *c, int pc);
t_proc			*fork_proc(t_arena *a, t_proc *p, int pc);
void			proc_exec_inst(t_proc *p);
int				proc_read_inst(t_proc *p, uint8_t mem[]);
int				proc_read_params(t_proc *p, uint8_t mem[]);

void			check_process(t_arena *a);
int				cmp_id(int *ref, t_champ *data);

void			update_mem(uint32_t *mem);
t_val			val(void *p, uint8_t s);
int				mem_mod(int addr);
int				idx_mod(int pc, int addr);
void			winner(t_arena *arena);
void			write_mem(int addr, t_val v, uint8_t mem[]);
void			read_mem(int addr, t_val v, uint8_t mem[]);
void			set_mem(uint32_t *mem, int addr, int size, int player);
int				get_value(t_proc *p, int *v, int index, t_type type);

t_header		empty_head(void);
int				err(const char *format, ...);
void			dump(uint8_t mem[], int mod);
void			proc_set(t_proc *p, int state);

void			i_live(t_proc *proc);
void			i_ld(t_proc *proc);
void			i_st(t_proc *proc);
void			i_aff(t_proc *proc);
void			i_zjmp(t_proc *proc);
void			i_add(t_proc *proc);
void			i_sub(t_proc *proc);
void			i_and(t_proc *proc);
void			i_or(t_proc *proc);
void			i_xor(t_proc *proc);
void			i_ldi(t_proc *proc);
void			i_sti(t_proc *proc);
void			i_lld(t_proc *proc);
void			i_lldi(t_proc *proc);
void			i_fork(t_proc *proc);
void			i_lfork(t_proc *proc);

#endif
