/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_check_argv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewen <yewen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 00:53:56 by yewen             #+#    #+#             */
/*   Updated: 2017/08/21 22:15:53 by abnaceur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "asm.h"

int	check_num_argv(char *argv)
{
	int	i;

	i = 0;
	if (argv[i] == '-')
		++i;
	while (argv[i] && argv[i] != SEPARATOR_CHAR)
	{
		if (!ft_isdigit(argv[i]) || i > 11)
			return (0);
		++i;
	}
	return (1);
}

int	check_register(char *argv, t_op op, int p)
{
	int	i;

	if ((T_REG & op.argv[p]) != T_REG)
		return (0);
	i = 0;
	while (argv[++i] && argv[i] != SEPARATOR_CHAR)
		if (!ft_isdigit(argv[i]) || i > 3)
			return (0);
	if (ft_atoi(argv + 1) <= 0 || ft_atoi(argv + 1) > REG_NUMBER)
		return (0);
	return (1);
}

int	check_direct(char *argv, t_op op, int p, t_asm *a)
{
	int		flag;
	char	*label;

	if ((T_DIR & op.argv[p]) != T_DIR)
		return (0);
	if (argv[1] == LABEL_CHAR)
	{
		flag = 0;
		label = ft_strchr(argv, SEPARATOR_CHAR) ? \
			ft_strsub(argv, 2, ft_strchr(argv, SEPARATOR_CHAR) - (argv + 2)) \
			: ft_strsub(argv, 2, ft_strlen(argv));
		if (rb_search(a->labels, label))
			flag = 1;
		free(label);
		if (!flag)
			return (0);
	}
	else if (!check_num_argv(argv + 1))
		return (0);
	return (1);
}

int	check_indirect(char *argv, t_op op, int p, t_asm *a)
{
	int		flag;
	char	*label;

	if ((T_IND & op.argv[p]) != T_IND)
		return (0);
	if (argv[0] == LABEL_CHAR)
	{
		flag = 0;
		label = ft_strchr(argv, SEPARATOR_CHAR) ? \
			ft_strsub(argv, 1, ft_strchr(argv, SEPARATOR_CHAR) - (argv + 1)) \
			: ft_strsub(argv, 1, ft_strlen(argv));
		if (rb_search(a->labels, label))
			flag = 1;
		free(label);
		if (!flag)
			return (0);
	}
	else if (!check_num_argv(argv))
		return (0);
	return (1);
}
