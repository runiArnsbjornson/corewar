/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 16:52:01 by jdebladi          #+#    #+#             */
/*   Updated: 2017/08/21 22:21:19 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "corewar.h"

static char	*parse_arg_d(t_arena *a, int *i, int argc, char *argv[])
{
	int	n;

	if (++*i >= argc)
		return ("Option error: -dump in the end");
	if (!ft_isint(argv[*i]))
		return ("Number followed by -dump is not a valid int");
	a->opts |= D_OPT;
	n = ft_atoi(argv[*i]);
	if (n <= 0)
		return ("Number followed by -dump is not a valid option");
	a->dump_cycles = n;
	return (NULL);
}

static char	*parse_arg_s(t_arena *a, int *i, int argc, char *argv[])
{
	int	n;

	if (++*i >= argc)
		return ("Option error: -s in the end");
	if (!ft_isint(argv[*i]))
		return ("Arguments followed by -s is not a valid number");
	a->opts |= S_OPT;
	n = ft_atoi(argv[*i]);
	if (n <= 0)
		return ("Number followed by -s is not a valid option");
	a->dump_cycles = n;
	return (NULL);
}

static char	*parse_arg_n(t_arena *a, int *i, int argc, char *argv[])
{
	if (++*i >= argc)
		return ("Option error: -n in the end");
	if (!ft_isint(argv[*i]))
		return ("Argument followed by -n is not a valid number");
	if (++*i >= argc)
		return ("No Champion file follows -n option");
	return (player(a, argv[*i], argv[*i - 1]));
}

static char	*parse_arg_v(t_arena *a, int *i, int argc, char *argv[])
{
	int	n;

	if (++*i >= argc)
		return ("Option error: -v in the end");
	if (!ft_isint(argv[*i]))
		return ("Verbose number followed by -v is not a valid int");
	a->opts |= V_OPT;
	n = ft_atoi(argv[*i]);
	if (n > 31 || n < 0)
		return ("Verbose number followed by -v is not a valid option");
	a->verbose_lvl = n;
	return (NULL);
}

char		*parse_arg(t_arena *a, int argc, char *argv[])
{
	int		i;
	char	*err_msg;

	i = 0;
	while (++i < argc)
	{
		if (!ft_strcmp("-a", argv[i]))
			a->opts |= A_OPT;
		else if (!ft_strcmp("-dump", argv[i]) || !ft_strcmp("-d", argv[i]))
			err_msg = parse_arg_d(a, &i, argc, argv);
		else if (!ft_strcmp("-s", argv[i]))
			err_msg = parse_arg_s(a, &i, argc, argv);
		else if (!ft_strcmp("-v", argv[i]))
			err_msg = parse_arg_v(a, &i, argc, argv);
		else if (!ft_strcmp("-n", argv[i]))
			err_msg = parse_arg_n(a, &i, argc, argv);
		else
			break ;
		if (err_msg)
			return (err_msg);
	}
	while (i < argc)
		if ((err_msg = player(a, argv[i++], NULL)))
			return (err_msg);
	return (err_msg);
}
