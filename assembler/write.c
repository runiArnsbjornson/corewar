/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnaceur <abnaceur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 11:10:24 by abnaceur          #+#    #+#             */
/*   Updated: 2017/08/21 22:17:34 by abnaceur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "asm.h"

static char	*create_file(char *file, int *fd)
{
	char	*cor_file;
	size_t	len;

	len = ft_strlen(file) + 2;
	if (!(cor_file = ft_memalloc(len + 1)))
		return ("Malloc error");
	ft_strcpy(cor_file, file);
	ft_strcpy(cor_file + len - 3, "cor");
	if ((*fd = open(cor_file, O_WRONLY | O_EXCL | O_CREAT, 0644)) == -1)
	{
		perror(cor_file);
		free(cor_file);
		return ("write error");
	}
	ft_printf("%s => %s\n", file, cor_file);
	free(cor_file);
	return (NULL);
}

static void	write_prog_name(int fd, t_header *header)
{
	int		i;
	long	n;
	int		count;

	count = 0;
	n = COREWAR_EXEC_MAGIC;
	while (n != 0)
	{
		n /= 256;
		++count;
	}
	while (4 - count)
	{
		ft_putchar_fd(0x0, fd);
		++count;
	}
	puthex_fd(COREWAR_EXEC_MAGIC, fd);
	i = 0;
	while (header->prog_name[i])
		ft_putchar_fd(header->prog_name[i++], fd);
	while (i++ < PROG_NAME_LENGTH)
		ft_putchar_fd(0x0, fd);
}

static void	write_comment(int fd, t_header *header, int n_bytes)
{
	int		i;
	int		count;
	long	n;

	n = n_bytes;
	count = 0;
	while (n != 0)
	{
		n /= 0x100;
		++count;
	}
	while (8 - count)
	{
		ft_putchar_fd(0x0, fd);
		++count;
	}
	puthex_fd(n_bytes, fd);
	i = 0;
	while (header->comment[i])
		ft_putchar_fd(header->comment[i++], fd);
	while (i++ < COMMENT_LENGTH + 4)
		ft_putchar_fd(0x0, fd);
}

char		*write_file(t_asm *a, int n_lines, t_header *header)
{
	int		fd;
	int		count;
	char	*err_msg;

	(void)n_lines;
	if ((err_msg = create_file(a->file, &fd)))
		return (err_msg);
	count = set_label(a);
	ft_printf("Name: %s\nComment: %s\n", header->prog_name, header->comment);
	write_prog_name(fd, header);
	write_comment(fd, header, count);
	write_instruction(a, fd, n_lines);
	close(fd);
	return (NULL);
}

void		puthex_fd(long code, int fd)
{
	if (code >= 0x100)
	{
		puthex_fd(code / 0x100, fd);
		puthex_fd(code % 0x100, fd);
	}
	else
		ft_putchar_fd(code, fd);
}
