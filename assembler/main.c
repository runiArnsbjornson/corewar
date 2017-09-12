/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnaceur <abnaceur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 21:11:32 by abnaceur          #+#    #+#             */
/*   Updated: 2017/08/21 22:15:36 by abnaceur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "asm.h"

static char	*check_filename(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 3)
		return ("Filename is too short");
	if (ft_strcmp(filename + len - 2, ".s"))
		return ("File has the incorrect extension");
	return (NULL);
}

int			main(int argc, char *argv[])
{
	char	*err_msg;

	if (argc != 2)
	{
		ft_dprintf(STDERR_FILENO, "usage: %s filename.s\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if ((err_msg = check_filename(argv[1])))
	{
		ft_dprintf(STDERR_FILENO, "%s: %s\n", *argv, err_msg);
		exit(EXIT_FAILURE);
	}
	if ((err_msg = run(argv[1])))
	{
		if (!ft_strcmp("open error", err_msg))
			perror(argv[1]);
		else if (!ft_strcmp("write error", err_msg))
			;
		else
			ft_dprintf(STDERR_FILENO, "%s: %s\n", *argv, err_msg);
		exit(EXIT_FAILURE);
	}
	return (0);
}
