/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnaceur <abnaceur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 02:23:09 by abnaceur          #+#    #+#             */
/*   Updated: 2017/08/21 22:10:47 by abnaceur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# include "libft.h"
# include "op.h"

typedef struct	s_label
{
	char	*name;
	int		index;
	int		first_byte;
}				t_label;

typedef struct	s_line
{
	int		label;
	char	*op;
	char	*argv;
}				t_line;

typedef struct	s_asm
{
	char		*file;
	char		**lines;
	t_line		**tlines;
	int			n_lines;
	t_header	*header;
	t_rb		*labels;
}				t_asm;

typedef struct	s_write
{
	int		id_ins;
	int		cursor;
	int		instruction_cursor;
	t_op	op;
}				t_write;

char			*run(char *file);
char			*asm_read(const int fd, t_asm *a);
char			*parse_header(t_asm *a);
char			*parse_line(t_asm *a);
char			*parse_fetch_op(char **line, t_line *tl);
char			*parse_fetch_argv(char *line, t_line *tl, t_asm *a);
int				fetch_op_id(char *name);
int				check_register(char *argv, t_op op, int p);
int				check_direct(char *argv, t_op op, int p, t_asm *a);
int				check_indirect(char *argv, t_op op, int p, t_asm *a);
char			*write_file(t_asm *a, int n_lines, t_header *header);
void			puthex_fd(long code, int fd);
int				set_label(t_asm *a);
void			write_instruction(t_asm *a, int fd, int n_lines);
void			write_argv(t_asm *a, t_write *w, char *argv, int fd);

#endif
